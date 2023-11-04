/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwindow
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelLogin;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineLogin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelPassword;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *linePassword;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *buttonSignIn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *buttonLogIn;

    void setupUi(QDialog *loginwindow)
    {
        if (loginwindow->objectName().isEmpty())
            loginwindow->setObjectName("loginwindow");
        loginwindow->resize(400, 300);
        groupBox = new QGroupBox(loginwindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 40, 251, 211));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 60, 216, 118));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelLogin = new QLabel(widget);
        labelLogin->setObjectName("labelLogin");

        horizontalLayout_3->addWidget(labelLogin);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lineLogin = new QLineEdit(widget);
        lineLogin->setObjectName("lineLogin");

        horizontalLayout_3->addWidget(lineLogin);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        labelPassword = new QLabel(widget);
        labelPassword->setObjectName("labelPassword");

        horizontalLayout_4->addWidget(labelPassword);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        linePassword = new QLineEdit(widget);
        linePassword->setObjectName("linePassword");

        horizontalLayout_4->addWidget(linePassword);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        buttonSignIn = new QPushButton(widget);
        buttonSignIn->setObjectName("buttonSignIn");

        horizontalLayout_5->addWidget(buttonSignIn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        buttonLogIn = new QPushButton(widget);
        buttonLogIn->setObjectName("buttonLogIn");

        horizontalLayout_5->addWidget(buttonLogIn);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(loginwindow);

        QMetaObject::connectSlotsByName(loginwindow);
    } // setupUi

    void retranslateUi(QDialog *loginwindow)
    {
        loginwindow->setWindowTitle(QCoreApplication::translate("loginwindow", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("loginwindow", "Log In", nullptr));
        labelLogin->setText(QCoreApplication::translate("loginwindow", "Login", nullptr));
        labelPassword->setText(QCoreApplication::translate("loginwindow", "Password", nullptr));
        buttonSignIn->setText(QCoreApplication::translate("loginwindow", "Sign In", nullptr));
        buttonLogIn->setText(QCoreApplication::translate("loginwindow", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginwindow: public Ui_loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
