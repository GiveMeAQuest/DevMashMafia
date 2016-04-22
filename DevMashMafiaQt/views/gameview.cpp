#include "gameview.h"
#include "ui_gameview.h"

GameView::GameView(QWidget *parent,
                   SocketWrapper* socket,
                   QString message) :
    QWidget(parent),
    ui(new Ui::GameView),
    socket(socket),
    role(message)
{
    ui->setupUi(this);
    ui->label_2->setText(role);
}

GameView::~GameView()
{
    delete ui;
}
