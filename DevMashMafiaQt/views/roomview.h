#ifndef ROOMVIEW_H
#define ROOMVIEW_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonObject>

#include "socketwrapper.h"

namespace Ui {
class RoomView;
}

class RoomView : public QWidget
{
    Q_OBJECT

public:
    explicit RoomView(QWidget *parent = 0,
                      SocketWrapper *socket = 0,
                      int roomId = 0,
                      bool isHost = false);
    ~RoomView();

private:
    Ui::RoomView *ui;
    SocketWrapper *socket;
    QJsonArray playersArray;
    int roomId;
    bool isHost;
    void updatePlayers();

Q_SIGNALS:
    void getWaitingPlayers();
    void leaveRoom();
    void startGame();

public Q_SLOTS:
    void players(QJsonArray players);
    void playerJoin(QJsonObject player);
    void playerLeft(int player_id);
private Q_SLOTS:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // ROOMVIEW_H
