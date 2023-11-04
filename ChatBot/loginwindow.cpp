#include <QMessageBox>

#include "loginwindow.h"
#include "ui_loginwindow.h"

loginwindow::loginwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);
}

loginwindow::~loginwindow()
{
    delete ui;
}

///по нажатию кнопки Log In, закрываем окно loginwindow и открываем окно MainWindow;
void loginwindow::on_buttonLogIn_clicked()
{
    this->close();
    MainWindow *w = new MainWindow();
    ///w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
}

///по нажатию кнопки Sign In, закрываем окно loginwindow и открываем окно signinwindow;
void loginwindow::on_buttonSignIn_clicked()
{
    this->close();
    signinwindow *w = new signinwindow();
    ///w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
}

