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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginwindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineLogin;
    QLineEdit *linePassword;
    QLabel *label_3;
    QPushButton *buttonLogIn;
    QPushButton *buttonSignIn;

    void setupUi(QDialog *loginwindow)
    {
        if (loginwindow->objectName().isEmpty())
            loginwindow->setObjectName("loginwindow");
        loginwindow->resize(585, 450);
        loginwindow->setMinimumSize(QSize(585, 450));
        loginwindow->setMaximumSize(QSize(585, 450));
        loginwindow->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 242, 244);\n"
"\n"
""));
        label = new QLabel(loginwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 240, 450));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/img/LUM3.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(loginwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 110, 261, 32));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font-size:  24px; \n"
"font-weight:  600; \n"
"color:  rgb(48, 41, 46); "));
        lineLogin = new QLineEdit(loginwindow);
        lineLogin->setObjectName("lineLogin");
        lineLogin->setGeometry(QRect(260, 250, 261, 22));
        lineLogin->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 0px;\n"
"	border-bottom: 1px solid #8d99ae;\n"
"	color: #2b2d42;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"	background-color: #edf2f4;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 0px;\n"
"	background-color: #edf2f4;\n"
"	border-bottom: 1px solid #2b2d42;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 0px;\n"
"	background-color: #edf2f4;\n"
"	border-bottom: 1px solid #2b2d42;\n"
"}\n"
""));
        linePassword = new QLineEdit(loginwindow);
        linePassword->setObjectName("linePassword");
        linePassword->setGeometry(QRect(260, 290, 261, 22));
        linePassword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 0px;\n"
"	border-bottom: 1px solid #8d99ae;\n"
"	color: #2b2d42;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"	background-color: #edf2f4;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 0px;\n"
"	background-color: #edf2f4;\n"
"	border-bottom: 1px solid #2b2d42;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 0px;\n"
"	background-color: #edf2f4;\n"
"	border-bottom: 1px solid #2b2d42;\n"
"}\n"
""));
        linePassword->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(loginwindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 160, 261, 71));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setStyleSheet(QString::fromUtf8("font-size:  16px; \n"
"font-weight:  300; \n"
"color:  rgb(48, 41, 46); "));
        label_3->setWordWrap(true);
        buttonLogIn = new QPushButton(loginwindow);
        buttonLogIn->setObjectName("buttonLogIn");
        buttonLogIn->setGeometry(QRect(412, 409, 173, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonLogIn->sizePolicy().hasHeightForWidth());
        buttonLogIn->setSizePolicy(sizePolicy1);
        buttonLogIn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  color: rgb(237, 242, 244); /* \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"  border: 0px; /*\320\263\321\200\320\260\320\275\320\270\321\206\320\260*/\n"
"  background-color: rgb(239, 35, 60); /* \321\204\320\276\320\275 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"} \n"
"QPushButton:hover { background-color: rgb(217, 4, 41); } /* \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 \320\272\321\203\321\200\321\201\320\276\321\200\320\260 \320\274\321\213\321\210\320\272\320\270 */\n"
"QPushButton:focus { background-color: rgb(217, 4, 41); } /* \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */"));
        buttonSignIn = new QPushButton(loginwindow);
        buttonSignIn->setObjectName("buttonSignIn");
        buttonSignIn->setGeometry(QRect(240, 409, 172, 41));
        sizePolicy1.setHeightForWidth(buttonSignIn->sizePolicy().hasHeightForWidth());
        buttonSignIn->setSizePolicy(sizePolicy1);
        buttonSignIn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  color: rgb(237, 242, 244); /* \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"  border: 0px; /* \320\263\321\200\320\260\320\275\320\270\321\206\320\260*/\n"
"  background-color: rgb(141, 153, 174); /* \321\204\320\276\320\275 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"} \n"
"QPushButton:hover { background-color: rgb(43, 45, 66); } /* \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 \320\272\321\203\321\200\321\201\320\276\321\200\320\260 \320\274\321\213\321\210\320\272\320\270 */\n"
"QPushButton:focus { background-color: rgb(43, 45, 66); } /* \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */"));

        retranslateUi(loginwindow);

        buttonLogIn->setDefault(true);


        QMetaObject::connectSlotsByName(loginwindow);
    } // setupUi

    void retranslateUi(QDialog *loginwindow)
    {
        loginwindow->setWindowTitle(QCoreApplication::translate("loginwindow", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("loginwindow", "\320\237\321\200\320\270\320\262\320\265\321\202, \321\217 \321\207\320\260\321\202-\320\261\320\276\321\202 LUM", nullptr));
        lineLogin->setPlaceholderText(QCoreApplication::translate("loginwindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        linePassword->setPlaceholderText(QCoreApplication::translate("loginwindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("loginwindow", "\320\222\320\276\320\271\320\264\320\270 \320\262 \320\260\320\272\320\272\320\260\321\203\320\275\321\202, \320\260 \320\265\321\201\320\273\320\270 \320\274\321\213 \320\265\321\211\320\265 \320\275\320\265 \320\267\320\275\320\260\320\272\320\276\320\274\321\213, \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\321\203\320\271\321\201\321\217 \320\270 \320\275\320\260\321\207\320\270\320\275\320\260\320\271 \320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        buttonLogIn->setText(QCoreApplication::translate("loginwindow", "\320\220\320\222\320\242\320\236\320\240\320\230\320\227\320\220\320\246\320\230\320\257", nullptr));
        buttonSignIn->setText(QCoreApplication::translate("loginwindow", "\320\240\320\225\320\223\320\230\320\241\320\242\320\240\320\220\320\246\320\230\320\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginwindow: public Ui_loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
