/********************************************************************************
** Form generated from reading UI file 'voteview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOTEVIEW_H
#define UI_VOTEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VoteView
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *VoteView)
    {
        if (VoteView->objectName().isEmpty())
            VoteView->setObjectName(QStringLiteral("VoteView"));
        VoteView->resize(391, 320);
        verticalLayout = new QVBoxLayout(VoteView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(VoteView);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(VoteView);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);

        pushButton = new QPushButton(VoteView);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(VoteView);

        QMetaObject::connectSlotsByName(VoteView);
    } // setupUi

    void retranslateUi(QWidget *VoteView)
    {
        VoteView->setWindowTitle(QApplication::translate("VoteView", "Form", 0));
        label->setText(QApplication::translate("VoteView", "Voting", 0));
        pushButton->setText(QApplication::translate("VoteView", "Vote", 0));
    } // retranslateUi

};

namespace Ui {
    class VoteView: public Ui_VoteView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOTEVIEW_H
