#include "roomview.h"
#include "ui_roomview.h"

RoomView::RoomView(QWidget *parent,
                   SocketWrapper *socket,
                   int roomId,
                   bool isHost) :
    QWidget(parent),
    ui(new Ui::RoomView),
    socket(socket),
    roomId(roomId),
    isHost(isHost)
{
    ui->setupUi(this);
    if (!isHost) {
        ui->pushButton_2->setVisible(false);
        ui->label_2->setVisible(false);
    }
    ui->roomId->setText(QString::number(roomId));

    connect(this, SIGNAL(getWaitingPlayers()),
            socket, SLOT(getWaitingPlayers()));
    connect(this, SIGNAL(leaveRoom()),
            socket, SLOT(leaveRoom()));
    connect(this, SIGNAL(startGame()),
            socket, SLOT(startGame()));
    connect(socket, SIGNAL(players(QJsonArray)),
            this, SLOT(players(QJsonArray)));
    connect(socket, SIGNAL(playerJoin(QJsonObject)),
            this, SLOT(playerJoin(QJsonObject)));
    connect(socket, SIGNAL(playerLeft(int)),
            this, SLOT(playerLeft(int)));
    Q_EMIT getWaitingPlayers();
}

void RoomView::players(QJsonArray players)
{
    this->playersArray = players;
    updatePlayers();
}

void RoomView::playerJoin(QJsonObject player)
{
    playersArray.append(player);
    ui->listWidget->addItem(player["nickname"].toString());
}

void RoomView::playerLeft(int player_id)
{
    for (int i = 0; i < playersArray.size(); i++) {
        if (playersArray[i].toObject()["id"] == player_id) {
            playersArray.removeAt(i);
            delete ui->listWidget->item(i);
            break;
        }
    }

}

void RoomView::updatePlayers()
{
    ui->listWidget->clear();
    for (int i = 0; i < playersArray.size(); i++) {
        QString item = playersArray[i].toObject()["nickname"].toString();
        ui->listWidget->addItem(item);
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

void RoomView::on_pushButton_2_clicked()
{
    Q_EMIT startGame();
}
