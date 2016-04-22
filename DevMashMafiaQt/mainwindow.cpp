#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

#include "views/roomjoinview.h"
#include "views/roomview.h"
#include "views/gameview.h"
#include "views/voteview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    socket(new SocketWrapper(this))
{
    ui->setupUi(this);

    setView(ROOM_JOIN_VIEW);
    connect(socket, SIGNAL(roomJoined(int, bool)),
            this, SLOT(roomJoined(int, bool)));
    connect(socket, SIGNAL(roomLeft()),
            this, SLOT(roomLeft()));
    connect(socket, SIGNAL(role(QString)),
            this, SLOT(roleChoosed(QString)));
    connect(socket, SIGNAL(nightBegin()),
            this, SLOT(nightBegin()));
    connect(socket, SIGNAL(nightEnd()),
            this, SLOT(nightEnd()));
    connect(socket, SIGNAL(dayBegin(QJsonObject)),
            this, SLOT(dayBegin(QJsonObject)));
    connect(socket, SIGNAL(citizenEnd(QJsonObject)),
            this, SLOT(citizenEnd(QJsonObject)));
    connect(socket, SIGNAL(mafiaBegin(QJsonArray, int)),
            this, SLOT(mafiaBegin(QJsonArray, int)));
    connect(this, SIGNAL(mafiaChoosen(int, int)),
            socket, SLOT(mafiaChoosen(int, int)));
}

void MainWindow::setView(WINDOW_VIEW view) {
    switch (view) {
    case ROOM_JOIN_VIEW: {
        curView = new RoomJoinView(this, socket);
    } break;
    case ROOM_VIEW: {
        curView = new RoomView(this, socket, curRoomId, isHost);
    } break;
    case GAME_VIEW: {
        curView = new GameView(this, socket, role);
    } break;
    case VOTE_VIEW: {
        curView = new VoteView(this, &optionsStr);
    } break;
    default: {
        return;
    }
    }
    const QRect &viewRect = curView->geometry();
    const QRect &thisRect = this->geometry();
    this->setGeometry(thisRect.x(), thisRect.y(), viewRect.width(), viewRect.height());
    this->setCentralWidget(curView);
}

void MainWindow::roomJoined(int room_id, bool isHost)
{
    curRoomId = room_id;
    this->isHost = isHost;
    setView(ROOM_VIEW);
}

void MainWindow::roomLeft()
{
    setView(ROOM_JOIN_VIEW);
}

void MainWindow::roleChoosed(QString role) {
    this->role = role;
    setView(GAME_VIEW);
}

void MainWindow::nightBegin() {
    this->role = "Night begins";
    setView(GAME_VIEW);
}

void MainWindow::nightEnd()
{
    this->role = "Night ends";
    setView(GAME_VIEW);
}

void MainWindow::dayBegin(QJsonObject obj) {
    QJsonObject killedPlayer = obj["killed player"].toObject();
    QJsonObject alibiedPlayer = obj["alibied_player"].toObject();
    if (killedPlayer["id"] == -1) {
        role = "Nobody died this night, uh. \n";
    } else {
        role = obj["nickname"].toString();
        role += " died this nighy, yeah!\n";
    }
    if (alibiedPlayer["id"] != -1) {
        role += alibiedPlayer["nickname"].toString();
        role += " has alibi for this day,  umm";
    }
    setView(GAME_VIEW);
}

void MainWindow::citizenEnd(QJsonObject obj) {
    role = obj["arrested_player"].toObject()["nickname"].toString();
    role += " was choosen to be arrested";
    setView(GAME_VIEW);
}

void MainWindow::mafiaBegin(QJsonArray players, int player_type) {
    optionsStr = QVector<QString>();
    for (int i = 0; i < players.size(); i++) {
        optionsStr.append(players.at(i).toObject()["nickname"].toString());
    }
    voteMode = (VoteMode) player_type;
    this->players = players;
    setView(VOTE_VIEW);
}

void MainWindow::socketFailed()
{
    ui->statusBar->setWindowTitle("Socket has been failed");
}

void MainWindow::socketClosed(const client::close_reason &reason)
{
    ui->statusBar->setWindowTitle("Socket has been closed for reason: ");
}

void MainWindow::optionChoosen(int i) {
    //qDebug() << "Option choose is" << i;
    int index = players.at(i).toObject()["id"].toInt();
    Q_EMIT mafiaChoosen(index, voteMode);
}

MainWindow::~MainWindow()
{
    delete ui;
}

