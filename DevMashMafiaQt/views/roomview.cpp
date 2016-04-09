#include "roomview.h"
#include "ui_roomview.h"

RoomView::RoomView(QWidget *parent,
                   SocketWrapper *socket,
                   int roomId) :
    QWidget(parent),
    ui(new Ui::RoomView),
    socket(socket),
    roomId(roomId)
{
    ui->setupUi(this);
    ui->roomId->setText(QString::number(roomId));
    connect(this, SIGNAL(getWaitingPlayers()),
            socket, SLOT(getWaitingPlayers()));
    connect(socket, SIGNAL(players(QJsonArray)),
            this, SLOT(players(QJsonArray)));
    connect(this, SIGNAL(leaveRoom()),
            socket, SLOT(leaveRoom()));
    Q_EMIT getWaitingPlayers();
}

void RoomView::players(QJsonArray players)
{
    ui->listWidget->clear();
    for (int i = 0; i < players.size(); i++) {
        ui->listWidget->addItem(players[i].toObject()["nickname"].toString());
    }
}

RoomView::~RoomView()
{
    delete ui;
}

void RoomView::on_pushButton_clicked()
{
    Q_EMIT leaveRoom();
}
