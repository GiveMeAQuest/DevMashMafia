#ifndef SOCKETWRAPPER_H
#define SOCKETWRAPPER_H

#define MAIN_URL "http://devmashmafia2.herokuapp.com/"
//#define MAIN_URL "http://192.168.1.109:3000/"
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
#define START_GAME_EVENT "start game"
#define MAFIA_VOTE_EVENT "mafia vote"
#define SHERIFF_VOTE_EVENT "sheriff vote"
#define DOCTOR_VOTE_EVENT "doctor vote"
#define PROSTITUTE_VOTE_EVENT "prostitute vote"
#define CITIZEN_VOTE_EVENT "citizen vote"
#define ROLE_EVENT "role"
#define PHASE_CHANGED_EVENT "phase changed"
#define ERR_EVENT "err"

#define MAFIA_BEGIN "mafia begin"
#define SHERIFF_BEGIN "sheriff begin"
#define DOCTOR_BEGIN "doctor begin"
#define PROSTITUTE_BEGIN "prostitute begin"
#define CITIZEN_BEGIN "citizen begin"

#define NIGHT_BEGIN "night begin"
#define NIGHT_END "night end"
#define DAY_BEGIN "day begin"
#define CITIZEN_END "citizen end"

#include <QObject>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>

#include <sio_client.h>

#include "votemode.h"

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
    bool isHost;
    std::string getSocketEvent(QString const& event);
    void sendEvent(QString event, QJsonObject &params);
    void printEvent(const string &name, const message::ptr &data);
    void OnConnected(std::string const& nsp);
    void OnJoinedRoom(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnCreatedRoom(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnPlayers(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnPlayerJoined(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnPlayerLeft(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnRoomLeft(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnRole(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnNightBegin(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnPhaseChanged(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnErr(std::string const& name,message::ptr const& data,bool hasAck,message::list &ack_resp);
    void OnClosed(client::close_reason const& reason);
    void OnFailed();

Q_SIGNALS:
    void socketClose(client::close_reason const& reason);
    void socketFailed();
    void roomJoined(int room_id, bool isHost);
    void players(QJsonArray players);
    void playerJoin(QJsonObject player);
    void playerLeft(int player_id);
    void roomLeft();
    void role(QString role);
    void nightBegin();
    void nightEnd();
    void dayBegin(QJsonObject);
    void citizenEnd(QJsonObject);
    void mafiaBegin(QJsonArray, int);
    void error(QString mess);

private Q_SLOTS:
    void httpReplyFinished(QNetworkReply*);
public Q_SLOTS:
    void roomJoin(QString nickname, int room_id, bool isHost);
    void createRoom(QString nickname, int players_count);
    void getWaitingPlayers();
    void leaveRoom();
    void startGame();
    void mafiaChoosen(int, int);
};

#endif // SOCKETWRAPPER_H
