#ifndef VOTEVIEW_H
#define VOTEVIEW_H

#include <QWidget>

namespace Ui {
class VoteView;
}

class VoteView : public QWidget
{
    Q_OBJECT

public:
    explicit VoteView(QWidget *parent = 0);
    ~VoteView();

private:
    Ui::VoteView *ui;
};

#endif // VOTEVIEW_H
