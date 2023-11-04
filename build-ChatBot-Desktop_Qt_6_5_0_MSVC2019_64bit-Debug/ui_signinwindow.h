/********************************************************************************
** Form generated from reading UI file 'signinwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINWINDOW_H
#define UI_SIGNINWINDOW_H

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

class Ui_signinwindow
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
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

    void setupUi(QDialog *signinwindow)
    {
        if (signinwindow->objectName().isEmpty())
            signinwindow->setObjectName("signinwindow");
        signinwindow->resize(400, 300);
        groupBox = new QGroupBox(signinwindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(70, 30, 251, 211));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 60, 216, 118));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelLogin = new QLabel(layoutWidget);
        labelLogin->setObjectName("labelLogin");

        horizontalLayout_3->addWidget(labelLogin);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lineLogin = new QLineEdit(layoutWidget);
        lineLogin->setObjectName("lineLogin");

        horizontalLayout_3->addWidget(lineLogin);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        labelPassword = new QLabel(layoutWidget);
        labelPassword->setObjectName("labelPassword");

        horizontalLayout_4->addWidget(labelPassword);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        linePassword = new QLineEdit(layoutWidget);
        linePassword->setObjectName("linePassword");

        horizontalLayout_4->addWidget(linePassword);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        buttonSignIn = new QPushButton(layoutWidget);
        buttonSignIn->setObjectName("buttonSignIn");

        horizontalLayout_5->addWidget(buttonSignIn);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(signinwindow);

        QMetaObject::connectSlotsByName(signinwindow);
    } // setupUi

    void retranslateUi(QDialog *signinwindow)
    {
        signinwindow->setWindowTitle(QCoreApplication::translate("signinwindow", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("signinwindow", "Sign In", nullptr));
        labelLogin->setText(QCoreApplication::translate("signinwindow", "Login", nullptr));
        labelPassword->setText(QCoreApplication::translate("signinwindow", "Password", nullptr));
        buttonSignIn->setText(QCoreApplication::translate("signinwindow", "Sign In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signinwindow: public Ui_signinwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINWINDOW_H
