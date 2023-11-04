#include "signinwindow.h"
#include "ui_signinwindow.h"

signinwindow::signinwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signinwindow)
{
    ui->setupUi(this);
}

signinwindow::~signinwindow()
{
    delete ui;
}

///по нажатию кнопки Sign In, закрываем окно signinwindow и открываем окно loginwindow;
void signinwindow::on_buttonSignIn_clicked()
{
    this->close();
    loginwindow *w = new loginwindow();
    //window->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
}

