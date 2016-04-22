#include "voteview.h"
#include "ui_voteview.h"

#include <QDebug>

VoteView::VoteView(QWidget *parent,
                   QVector<QString> *options) :
    QWidget(parent),
    options(options),
    ui(new Ui::VoteView)
{
    ui->setupUi(this);
    for (int i = 0; i < options->size(); i++) {
        ui->listWidget->addItem(options->at(i));
    }
    connect(this, SIGNAL(choosenOption(int)),
            parent, SLOT(optionChoosen(int)));
}

VoteView::~VoteView()
{
    delete ui;
}

void VoteView::on_pushButton_clicked()
{
    int index = ui->listWidget->currentIndex().row();
    Q_EMIT choosenOption(index);
}
