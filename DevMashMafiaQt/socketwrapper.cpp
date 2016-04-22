#include "socketwrapper.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QDebug>

SocketWrapper::SocketWrapper(QObject *parent) :
    QObject(parent),
    _io(new client())
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
      connect(manager, SIGNAL(finished(QNetworkReply*)),
              this, SLOT(httpReplyFinished(QNetworkReply*)));

    QString eventsUrl(MAIN_URL);
    eventsUrl.append("api/events");
    manager->get(QNetworkRequest(QUrl(eventsUrl)));

    using std::placeholders::_1;
    using std::placeholders::_2;
    using std::placeholders::_3;
    using std::placeholders::_4;
    _io->set_socket_open_listener(std::bind(&SocketWrapper::OnConnected,this,std::placeholders::_1));
    _io->set_close_listener(std::bind(&SocketWrapper::OnClosed,this,_1));
    _io->set_fail_listener(std::bind(&SocketWrapper::OnFailed,this));
    _io->connect(MAIN_URL);
}

void SocketWrapper::OnConnected(const string &nsp)
{
    qDebug() << "Socket has been connected";
}

void SocketWrapper::OnClosed(client::close_reason const& reason)
{
    qDebug() << "Socket has been disconnected";
}

void SocketWrapper::OnFailed()
{
    qDebug() << "Socket has been failed";
}

#ifdef WIN32
#define BIND_EVENT(IO,EV,FN) \
    do{ \
        socket::event_listener_aux l = std::bind(&FN,this,_1,_2,_3,_4);\
        IO->on(EV,l);\
    } while(0)

#else
#define BIND_EVENT(IO,EV,FN) \
    IO->on(EV,std::bind(&FN,this,_1,_2,_3,_4))
#endif
void SocketWrapper::httpReplyFinished(QNetworkReply *reply)
{
//    qDebug() << reply->readLine().toStdString().c_str();
    socketEvents = QJsonDocument::fromJson(reply->readLine()).object();
    socketEventNames = QJsonObject();
    for (auto it = socketEvents.begin(); it != socketEvents.end(); it++) {
        socketEventNames[it.value().toString()] = it.key();
    }

    socket::ptr sock =_io->socket();
    using std::placeholders::_1;
    using std::placeholders::_2;
    using std::placeholders::_3;
    using std::placeholders::_4;
    BIND_EVENT(sock,getSocketEvent(JOINED_ROOM_EVENT),SocketWrapper::OnJoinedRoom);
    BIND_EVENT(sock,getSocketEvent(CREATED_ROOM_EVENT),SocketWrapper::OnCreatedRoom);
    BIND_EVENT(sock,getSocketEvent(PLAYERS_EVENT),SocketWrapper::OnPlayers);
    BIND_EVENT(sock,getSocketEvent(PLAYER_JOINED_EVENT),SocketWrapper::OnPlayerJoined);
    BIND_EVENT(sock,getSocketEvent(PLAYER_LEFT_EVENT),SocketWrapper::OnPlayerLeft);
    BIND_EVENT(sock,getSocketEvent(ROOM_LEFT_EVENT),SocketWrapper::OnRoomLeft);
    BIND_EVENT(sock,getSocketEvent(ROLE_EVENT),SocketWrapper::OnRole);
    BIND_EVENT(sock,getSocketEvent(PHASE_CHANGED_EVENT),SocketWrapper::OnPhaseChanged);
    BIND_EVENT(sock,getSocketEvent(ERR_EVENT),SocketWrapper::OnErr);
}

void SocketWrapper::printEvent(const string &name, const message::ptr &data)
{
    QString eventName = socketEventNames[name.c_str()].toString();
    std::string message;
    if (data.get() != NULL) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data->get_string().c_str());
        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Compact);
        message = std::string(bytes.data(), bytes.length());
    } else {
        message = "{}";
    }
    qDebug() << "\nNew socket message:" << eventName << " "<< message.c_str();
}

void SocketWrapper::OnJoinedRoom(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name, data);
    Q_EMIT roomJoined(curRoomId, isHost);
}

void SocketWrapper::OnCreatedRoom(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name, data);
    QJsonObject json = QJsonDocument::fromJson(data->get_string().c_str()).object();
    int room_id = json["id"].toInt();
    curRoomId = room_id;
    Q_EMIT roomJoin(curNickname, room_id, true);
}

void SocketWrapper::OnPlayers(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name, data);
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data->get_string().c_str());
    QJsonObject jsonObj = jsonDoc.object();
    Q_EMIT players(jsonObj["players"].toArray());
}

void SocketWrapper::OnPlayerJoined(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name, data);
    QJsonObject player = QJsonDocument::fromJson(data->get_string().c_str()).object();
    Q_EMIT playerJoin(player);
}

void SocketWrapper::OnPlayerLeft(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name, data);
    QJsonObject player = QJsonDocument::fromJson(data->get_string().c_str()).object();
    int player_id = player["id"].toInt();
    Q_EMIT playerLeft(player_id);
}

void SocketWrapper::OnRoomLeft(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name, data);
    Q_EMIT roomLeft();
}

void SocketWrapper::OnRole(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp) {
    printEvent(name, data);
    QJsonObject roleObj = QJsonDocument::fromJson(data->get_string().c_str()).object();
    Q_EMIT role(roleObj["name"].toString());
}

void SocketWrapper::OnNightBegin(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp) {
    printEvent(name, data);
    Q_EMIT nightBegin();
}

void SocketWrapper::OnPhaseChanged(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp) {
    printEvent(name, data);
    QJsonObject obj = QJsonDocument::fromJson(data->get_string().c_str()).object();
    QString phaseName = obj["phase_name"].toString();
    if (!phaseName.compare(QString(MAFIA_BEGIN))) {
        QJsonArray players = obj["data"].toObject()["players"].toArray();
        Q_EMIT mafiaBegin(players, MAFIA);
    } else if (!phaseName.compare(QString(SHERIFF_BEGIN))) {
        QJsonArray players = obj["data"].toObject()["players"].toArray();
        Q_EMIT mafiaBegin(players, SHERIFF);
    } else if (!phaseName.compare(QString(DOCTOR_BEGIN))) {
        QJsonArray players = obj["data"].toObject()["players"].toArray();
        Q_EMIT mafiaBegin(players, DOCTOR);
    } else if (!phaseName.compare(QString(PROSTITUTE_BEGIN))) {
        QJsonArray players = obj["data"].toObject()["players"].toArray();
        Q_EMIT mafiaBegin(players, PROSTITUTE);
    } else if (!phaseName.compare(QString(CITIZEN_BEGIN))) {
        QJsonArray players = obj["data"].toObject()["players"].toArray();
        Q_EMIT mafiaBegin(players, CITIZEN);
    } else if (!phaseName.compare(QString(NIGHT_BEGIN))) {
        Q_EMIT nightBegin();
    } else if (!phaseName.compare(QString(NIGHT_END))) {
        Q_EMIT nightEnd();
    } else if (!phaseName.compare(QString(DAY_BEGIN))) {
        Q_EMIT dayBegin(obj["data"].toObject());
    } else if (!phaseName.compare(QString(CITIZEN_END))) {
        Q_EMIT citizenEnd(obj["data"].toObject());
    } else {
        qDebug() << "No phase implemented: " << phaseName;
    }
}

void SocketWrapper::OnErr(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name, data);
    Q_EMIT error(QString(data->get_string().c_str()));
}

void SocketWrapper::roomJoin(QString nickname, int room_id, bool isHost = false)
{
    QJsonObject params {
        {"nickname", nickname},
        {"room_id", room_id}
    };
    curRoomId = room_id;
    this->isHost = isHost;
    sendEvent(QString(JOIN_ROOM_EVENT), params);
}

void SocketWrapper::createRoom(QString nickname, int players_count)
{
    QJsonObject params {
        {"players", players_count}
    };
    sendEvent(QString(CREATE_ROOM_EVENT), params);
    curNickname = nickname;
}

void SocketWrapper::getWaitingPlayers()
{
    QJsonObject params;
    sendEvent(QString(GET_WAITING_PLAYERS_EVENT), params);
}

void SocketWrapper::leaveRoom()
{
    QJsonObject params;
    sendEvent(QString(LEAVE_ROOM_EVENT), params);
}


void SocketWrapper::startGame()
{
    QJsonObject params;
    sendEvent(QString(START_GAME_EVENT), params);
}


void SocketWrapper::mafiaChoosen(int player_id, int player_type)
{
    QJsonObject params {
        {"id", player_id}
    };
    QString event;
    switch (player_type) {
    case MAFIA: {
        event = QString(MAFIA_VOTE_EVENT);
    } break;
    case SHERIFF: {
        event = QString(SHERIFF_VOTE_EVENT);
    } break;
    case DOCTOR: {
        event = QString(DOCTOR_VOTE_EVENT);
    } break;
    case PROSTITUTE: {
        event = QString(PROSTITUTE_VOTE_EVENT);
    } break;
    case CITIZEN: {
        event = QString(CITIZEN_VOTE_EVENT);
    } break;
    default: {
        qDebug() << "SocketWrapper::mafiaChoosen uknow VoteMode " << player_type;
    }
    }

    sendEvent(event, params);
}


void SocketWrapper::sendEvent(QString event, QJsonObject &params)
{
    socket::ptr sock =_io->socket();
    QByteArray bytes = QJsonDocument(params).toJson(QJsonDocument::Compact);
    std::string message(bytes.data(), bytes.length());
    sock->emit(getSocketEvent(event), message);
    qDebug() << "\nSend socket" << event << message.c_str();
}

std::string SocketWrapper::getSocketEvent(QString const& event)
{
    return socketEvents[event].toString().toStdString();
}
