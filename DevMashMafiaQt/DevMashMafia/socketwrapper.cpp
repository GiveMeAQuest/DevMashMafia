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

}

void SocketWrapper::OnFailed()
{

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
    BIND_EVENT(sock,getSocketEvent(ERR_EVENT),SocketWrapper::OnErr);
}

void SocketWrapper::printEvent(const string &name)
{
    QString eventName = socketEventNames[name.c_str()].toString();
    qDebug() << "\nNew socket message:";
    qDebug() << eventName;
}

void SocketWrapper::OnJoinedRoom(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name);
    Q_EMIT roomJoined(curRoomId);
}

void SocketWrapper::OnCreatedRoom(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name);
    int room_id = data->get_int();
    curRoomId = room_id;
    Q_EMIT roomJoin(curNickname, room_id);
}

void SocketWrapper::OnPlayers(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name);
    Q_EMIT players(QJsonDocument::fromJson(data->get_string().c_str()).array());
}

void SocketWrapper::OnPlayerJoined(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name);
    getWaitingPlayers();
}

void SocketWrapper::OnPlayerLeft(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name);
    getWaitingPlayers();
}

void SocketWrapper::OnRoomLeft(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    Q_EMIT roomLeft();
}

void SocketWrapper::OnErr(const string &name, const message::ptr &data, bool hasAck, message::list &ack_resp)
{
    printEvent(name);
    const char *err_message = data->get_string().c_str();
    qDebug() << err_message;
    Q_EMIT error(QString(err_message));
}

void SocketWrapper::roomJoin(QString nickname, int room_id)
{
    QJsonObject params {
        {"nickname", nickname},
        {"room_id", room_id}
    };
    curRoomId = room_id;
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
