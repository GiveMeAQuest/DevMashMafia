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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    socket(new SocketWrapper(this))
{
    ui->setupUi(this);

    setView(ROOM_JOIN_VIEW);
    connect(socket, SIGNAL(roomJoined(int)),
            this, SLOT(roomJoined(int)));
    connect(socket, SIGNAL(roomLeft()),
            this, SLOT(roomLeft()));
}

void MainWindow::setView(WINDOW_VIEW view) {
    switch (view) {
    case ROOM_JOIN_VIEW: {
        curView = new RoomJoinView(this, socket);
    } break;
    case ROOM_VIEW: {
        curView = new RoomView(this, socket, curRoomId);
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

void MainWindow::roomJoined(int room_id)
{
    curRoomId = room_id;
    setView(ROOM_VIEW);
}

void MainWindow::roomLeft()
{
    setView(ROOM_JOIN_VIEW);
}

void MainWindow::socketFailed()
{
    ui->statusBar->setWindowTitle("Socket has been failed");
}

void MainWindow::socketClosed(const client::close_reason &reason)
{
    ui->statusBar->setWindowTitle("Socket has been closed for reason: ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

