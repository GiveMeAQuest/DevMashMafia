/********************************************************************************
** Form generated from reading UI file 'roomview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMVIEW_H
#define UI_ROOMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomView
{
public:
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *roomId;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QWidget *RoomView)
    {
        if (RoomView->objectName().isEmpty())
            RoomView->setObjectName(QStringLiteral("RoomView"));
        RoomView->resize(218, 213);
        horizontalLayout_2 = new QHBoxLayout(RoomView);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listWidget = new QListWidget(RoomView);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(RoomView);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        roomId = new QLabel(RoomView);
        roomId->setObjectName(QStringLiteral("roomId"));

        horizontalLayout->addWidget(roomId);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(RoomView);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        label_2 = new QLabel(RoomView);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(9);
        label_2->setFont(font);
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        pushButton = new QPushButton(RoomView);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        label_3 = new QLabel(RoomView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setWordWrap(true);

        verticalLayout->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(RoomView);

        QMetaObject::connectSlotsByName(RoomView);
    } // setupUi

    void retranslateUi(QWidget *RoomView)
    {
        RoomView->setWindowTitle(QApplication::translate("RoomView", "Form", 0));
        label->setText(QApplication::translate("RoomView", "Room id:", 0));
        roomId->setText(QString());
        pushButton_2->setText(QApplication::translate("RoomView", "Ready", 0));
        label_2->setText(QApplication::translate("RoomView", "Press when you are ready to start game", 0));
        pushButton->setText(QApplication::translate("RoomView", "Leave room", 0));
        label_3->setText(QApplication::translate("RoomView", "Press to leave room", 0));
    } // retranslateUi

};

namespace Ui {
    class RoomView: public Ui_RoomView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMVIEW_H
