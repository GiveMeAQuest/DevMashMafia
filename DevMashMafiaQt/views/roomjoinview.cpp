#include "roomjoinview.h"
#include "ui_roomjoinview.h"

RoomJoinView::RoomJoinView(QWidget *parent, SocketWrapper *socket) :
    QWidget(parent),
    ui(new Ui::RoomJoinView),
    socket(socket)
{
    ui->setupUi(this);
    connect(this, SIGNAL(roomJoin(QString, int)),
            socket, SLOT(roomJoin(QString,int)));
    connect(this, SIGNAL(createRoom(QString,int)),
            socket, SLOT(createRoom(QString,int)));
    connect(socket, SIGNAL(error(QString)),
             this, SLOT(socketError(QString)));
}


void RoomJoinView::on_pushButton_2_clicked()
{
    Q_EMIT createRoom(ui->lineEdit->text(), ui->lineEdit_3->text().toInt());
}

void RoomJoinView::on_pushButton_clicked()
{
    Q_EMIT roomJoin(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
}

void RoomJoinView::socketError(QString mess)
{
    ui->errorLabel->setText(mess);
}
