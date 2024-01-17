
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <ctime>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QRegularExpression>
#include <QKeyEvent>

#include "message.h"
#include "user.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "globals.cpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    // Обработка данных нажатия кнопки "отправить";
    void on_sendButton_clicked();

    // Обработчик данных полученных от объекта QNetworkAccessManager;
    void onResult(QNetworkReply *reply);


    void on_messageWindow_textChanged();

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *networkManager;

    QJsonObject readToJsonObject ();

    void getJson(QString url);

    QString multiplication(QString message);

    QString division(QString message);

    QString sum(QString message);

    QString difference(QString message);

    QString currency(QString message);

};

#endif // MAINWINDOW_H
