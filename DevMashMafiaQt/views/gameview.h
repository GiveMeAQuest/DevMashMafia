#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>

namespace Ui {
class GameView;
}

class GameView : public QWidget
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = 0);
    ~GameView();

private:
    Ui::GameView *ui;
};

#endif // GAMEVIEW_H
