#ifndef VOTEVIEW_H
#define VOTEVIEW_H

#include <QWidget>
#include <QVector>

namespace Ui {
class VoteView;
}

class VoteView : public QWidget
{
    Q_OBJECT

public:
    explicit VoteView(QWidget *parent = 0,
                      QVector<QString>* = 0);
    ~VoteView();

private Q_SLOTS:
    void on_pushButton_clicked();

Q_SIGNALS:
    void choosenOption(int);

private:
    Ui::VoteView *ui;
    QVector<QString> *options;
};

#endif // VOTEVIEW_H
