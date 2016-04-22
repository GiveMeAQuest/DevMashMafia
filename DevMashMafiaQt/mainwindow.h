#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QJsonArray>

#include "socketwrapper.h"

#include "votemode.h"

enum WINDOW_VIEW{
    ROOM_JOIN_VIEW,
    ROOM_VIEW,
    GAME_VIEW,
    VOTE_VIEW
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
    void roomJoined(int room_id, bool isHost);
    void roomLeft();
    void roleChoosed(QString role);
    void nightBegin();
    void nightEnd();
    void dayBegin(QJsonObject);
    void citizenEnd(QJsonObject);
    void mafiaBegin(QJsonArray, int);
    void optionChoosen(int);

Q_SIGNALS:
    void mafiaChoosen(int, int);

private:
    Ui::MainWindow *ui;
    QWidget *curView;
    SocketWrapper *socket;
    int curRoomId;
    bool isHost;
    QString role;
    VoteMode voteMode;
    QVector<QString> optionsStr;
    QJsonArray players;
    void setView(WINDOW_VIEW view);
};

#endif // MAINWINDOW_H

