#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>

#include "socketwrapper.h"

namespace Ui {
class GameView;
}

class GameView : public QWidget
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = 0,
                      SocketWrapper *socket = 0,
                      QString = 0);
    ~GameView();

private:
    Ui::GameView *ui;
    SocketWrapper *socket;
    QString role;
};

#endif // GAMEVIEW_H
