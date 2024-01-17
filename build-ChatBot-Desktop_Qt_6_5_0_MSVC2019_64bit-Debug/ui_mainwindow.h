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
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 242, 244);\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        chatWindow = new QTextBrowser(centralwidget);
        chatWindow->setObjectName("chatWindow");
        chatWindow->setGeometry(QRect(0, 50, 800, 500));
        chatWindow->setFocusPolicy(Qt::NoFocus);
        chatWindow->setAutoFillBackground(false);
        chatWindow->setStyleSheet(QString::fromUtf8("padding: 1em;\n"
"border: 0px;"));
        chatWindow->setLineWidth(6);
        nameChatbot = new QLabel(centralwidget);
        nameChatbot->setObjectName("nameChatbot");
        nameChatbot->setGeometry(QRect(10, 10, 221, 21));
        nameChatbot->setStyleSheet(QString::fromUtf8("font-size:  24px; \n"
"font-weight:  600; \n"
"color:  rgb(48, 41, 46); "));
        messageWindow = new QTextEdit(centralwidget);
        messageWindow->setObjectName("messageWindow");
        messageWindow->setGeometry(QRect(0, 550, 750, 50));
        messageWindow->setFocusPolicy(Qt::TabFocus);
        messageWindow->setStyleSheet(QString::fromUtf8("padding: 5px;\n"
"border: 0px;"));
        messageWindow->setTabChangesFocus(false);
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(750, 550, 50, 50));
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  color: rgb(237, 242, 244); /* \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"  border: 0px; /*\320\263\321\200\320\260\320\275\320\270\321\206\320\260*/\n"
"  background-color: rgb(239, 35, 60); /* \321\204\320\276\320\275 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"} \n"
"QPushButton:hover { background-color: rgb(217, 4, 41); } /* \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 \320\272\321\203\321\200\321\201\320\276\321\200\320\260 \320\274\321\213\321\210\320\272\320\270 */\n"
"QPushButton:focus { background-color: rgb(217, 4, 41); } /* \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */"));
        sendButton->setAutoDefault(false);
        MainWindow->setCentralWidget(centralwidget);
        chatWindow->raise();
        nameChatbot->raise();
        sendButton->raise();
        messageWindow->raise();

        retranslateUi(MainWindow);

        sendButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        nameChatbot->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">ChatBot  LUM ver. 0.1 (alpha)</span></p></body></html>", nullptr));
        messageWindow->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 ...", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
