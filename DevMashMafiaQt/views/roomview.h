#ifndef ROOMVIEW_H
#define ROOMVIEW_H

#include <QWidget>
#include <QJsonArray>

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
                      int roomId = 0);
    ~RoomView();

private:
    Ui::RoomView *ui;
    SocketWrapper *socket;
    int roomId;

Q_SIGNALS:
    void getWaitingPlayers();
    void leaveRoom();

public Q_SLOTS:
    void players(QJsonArray players);
private Q_SLOTS:
    void on_pushButton_clicked();
};

#endif // ROOMVIEW_H
