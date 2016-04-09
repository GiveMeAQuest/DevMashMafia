#ifndef SOCKETWRAPPER_H
#define SOCKETWRAPPER_H

#define MAIN_URL "http://devmashmafia.herokuapp.com/"
#define JOINED_ROOM_EVENT "room joined"
#define JOIN_ROOM_EVENT "join room"
#define CREATE_ROOM_EVENT "create room"
#define CREATED_ROOM_EVENT "room created"
#define GET_WAITING_PLAYERS_EVENT "get waiting players"
#define PLAYERS_EVENT "players"
#define PLAYER_JOINED_EVENT "player joined"
#define PLAYER_LEFT_EVENT "player left"
#define LEAVE_ROOM_EVENT "leave room"
#define ROOM_LEFT_EVENT "room left"
#define ERR_EVENT "err"

#include <QObject>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>

#include <sio_client.h>

using namespace sio;

class SocketWrapper : public QObject
{
    Q_OBJECT
public:
    explicit SocketWrapper(QObject *parent = 0);

private:
    std::unique_ptr<client> _io;
    QJsonObject socketEvents;
    QJsonObject socketEventNames;
    QString curNickname;
    int curRoomId;
    std::string getSocketEvent(QString const& event);
    void sendEvent(QString event, QJsonObject &params);
    void printEvent(const string &name);
    void OnConnected(std::string const& nsp);
    void OnJoinedRoom(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnCreatedRoom(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnPlayers(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnPlayerJoined(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnPlayerLeft(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnRoomLeft(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnErr(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnClosed(client::close_reason const& reason);
    void OnFailed();

Q_SIGNALS:
    void socketClose(client::close_reason const& reason);
    void socketFailed();
    void roomJoined(int room_id);
    void players(QJsonArray players);
    void roomLeft();
    void error(QString mess);

private Q_SLOTS:
    void httpReplyFinished(QNetworkReply*);
public Q_SLOTS:
    void roomJoin(QString nickname, int room_id);
    void createRoom(QString nickname, int players_count);
    void getWaitingPlayers();
    void leaveRoom();
};

#endif // SOCKETWRAPPER_H
