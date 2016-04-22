/********************************************************************************
** Form generated from reading UI file 'roomjoinview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMJOINVIEW_H
#define UI_ROOMJOINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomJoinView
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *errorLabel;
    QLabel *statusLabelJoin;

    void setupUi(QWidget *RoomJoinView)
    {
        if (RoomJoinView->objectName().isEmpty())
            RoomJoinView->setObjectName(QStringLiteral("RoomJoinView"));
        RoomJoinView->resize(309, 251);
        verticalLayout_3 = new QVBoxLayout(RoomJoinView);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_4->addItem(verticalSpacer_2);

        label = new QLabel(RoomJoinView);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit = new QLineEdit(RoomJoinView);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(RoomJoinView);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(RoomJoinView);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton = new QPushButton(RoomJoinView);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_7->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(RoomJoinView);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit_3 = new QLineEdit(RoomJoinView);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(RoomJoinView);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        errorLabel = new QLabel(RoomJoinView);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));

        horizontalLayout_9->addWidget(errorLabel);


        verticalLayout_3->addLayout(horizontalLayout_9);

        statusLabelJoin = new QLabel(RoomJoinView);
        statusLabelJoin->setObjectName(QStringLiteral("statusLabelJoin"));

        verticalLayout_3->addWidget(statusLabelJoin);


        retranslateUi(RoomJoinView);

        QMetaObject::connectSlotsByName(RoomJoinView);
    } // setupUi

    void retranslateUi(QWidget *RoomJoinView)
    {
        RoomJoinView->setWindowTitle(QApplication::translate("RoomJoinView", "Form", 0));
        label->setText(QApplication::translate("RoomJoinView", "Nickname:", 0));
        label_2->setText(QApplication::translate("RoomJoinView", "Room id:", 0));
        pushButton->setText(QApplication::translate("RoomJoinView", "Join room", 0));
        label_3->setText(QApplication::translate("RoomJoinView", "Player count:", 0));
        pushButton_2->setText(QApplication::translate("RoomJoinView", "Create room", 0));
        errorLabel->setText(QString());
        statusLabelJoin->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RoomJoinView: public Ui_RoomJoinView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMJOINVIEW_H
