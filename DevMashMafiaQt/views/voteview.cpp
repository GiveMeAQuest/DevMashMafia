#include "voteview.h"
#include "ui_voteview.h"

VoteView::VoteView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VoteView)
{
    ui->setupUi(this);
}

VoteView::~VoteView()
{
    delete ui;
}
