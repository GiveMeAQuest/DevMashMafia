/********************************************************************************
** Form generated from reading UI file 'gameview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEVIEW_H
#define UI_GAMEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;

    void setupUi(QWidget *GameView)
    {
        if (GameView->objectName().isEmpty())
            GameView->setObjectName(QStringLiteral("GameView"));
        GameView->resize(400, 300);
        verticalLayout = new QVBoxLayout(GameView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(GameView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GameView);

        QMetaObject::connectSlotsByName(GameView);
    } // setupUi

    void retranslateUi(QWidget *GameView)
    {
        GameView->setWindowTitle(QApplication::translate("GameView", "Form", 0));
        label_2->setText(QApplication::translate("GameView", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class GameView: public Ui_GameView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEVIEW_H
