#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonArray>

#include "socketwrapper.h"

enum WINDOW_VIEW{
    ROOM_JOIN_VIEW,
    ROOM_VIEW
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void socketClosed(client::close_reason const& reason);
    void socketFailed();
    void roomJoined(int room_id);
    void roomLeft();

private:
    Ui::MainWindow *ui;
    QWidget *curView;
    SocketWrapper *socket;
    int curRoomId;
    void setView(WINDOW_VIEW view);
};

#endif // MAINWINDOW_H
