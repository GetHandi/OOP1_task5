
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QString>

#include "mainwindow.h"
#include "signinwindow.h"
#include "message.h"
#include "user.h"
#include "ui_loginwindow.h"
#include "globals.cpp"


QT_BEGIN_NAMESPACE
namespace Ui {class loginwindow;}
QT_END_NAMESPACE

class loginwindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);
    ~loginwindow();

private slots:
    ///по нажатию кнопки Log In, закрываем окно loginwindow и открываем окно MainWindow;
    void on_buttonLogIn_clicked();

    ///по нажатию кнопки Sign In, закрываем окно loginwindow и открываем окно signinwindow;
    void on_buttonSignIn_clicked();

private:
    Ui::loginwindow *ui;
};

#endif // LOGINWINDOW_H
