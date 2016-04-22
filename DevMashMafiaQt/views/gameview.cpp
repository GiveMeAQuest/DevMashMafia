#include "gameview.h"
#include "ui_gameview.h"

GameView::GameView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameView)
{
    ui->setupUi(this);
}

GameView::~GameView()
{
    delete ui;
}
