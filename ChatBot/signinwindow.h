
#ifndef SIGNINWINDOW_H
#define SIGNINWINDOW_H

#include <QDialog>
#include <QMessageBox>

#include "message.h"
#include "user.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_signinwindow.h"
#include "globals.cpp"


QT_BEGIN_NAMESPACE
namespace Ui {
class signinwindow;
}
QT_END_NAMESPACE
class signinwindow : public QDialog
{
    Q_OBJECT

public:
    explicit signinwindow(QWidget *parent = nullptr);
    ~signinwindow();

private slots:
    ///по нажатию кнопки Sign In, закрываем окно signinwindow и открываем окно loginwindow;
    void on_buttonSignIn_clicked();

private:
    Ui::signinwindow *ui;
};

#endif // SIGNINWINDOW_H
