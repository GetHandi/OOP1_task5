/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *chatWindow;
    QLabel *nameChatbot;
    QTextEdit *messageWindow;
    QPushButton *sendButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 242, 244);\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        chatWindow = new QTextBrowser(centralwidget);
        chatWindow->setObjectName("chatWindow");
        chatWindow->setGeometry(QRect(0, 50, 800, 500));
        chatWindow->setAutoFillBackground(false);
        chatWindow->setLineWidth(6);
        nameChatbot = new QLabel(centralwidget);
        nameChatbot->setObjectName("nameChatbot");
        nameChatbot->setGeometry(QRect(10, 10, 171, 21));
        nameChatbot->setStyleSheet(QString::fromUtf8("font-size:  24px; \n"
"font-weight:  600; \n"
"color:  rgb(48, 41, 46); "));
        messageWindow = new QTextEdit(centralwidget);
        messageWindow->setObjectName("messageWindow");
        messageWindow->setGeometry(QRect(0, 550, 750, 50));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(750, 550, 50, 50));
        sendButton->setAutoDefault(false);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        sendButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        nameChatbot->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">ChatBot  LUM ver. 0.1</span></p></body></html>", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
