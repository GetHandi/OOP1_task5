#include "loginwindow.h"
#include "ui_loginwindow.h"

QString USER_NAME;

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

/// Обработка нажатия кнопки Log In;
void loginwindow::on_buttonLogIn_clicked()
{
    /// Если поля login и password пусты - ошибка;
    if (ui->lineLogin->text() == "" || ui->linePassword->text() == "")
    {
        QMessageBox::warning(this, "", "The login and password field cannot be empty");
    }
    else
    {
        User user;
        QFile file( USER_DATA );
        QDataStream stream( &file );
        file.open( QIODevice::ReadOnly );

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// проверка login'a на совпадение и получение последнего id;
        do {
            stream >> user;
            if (user.getLogin() == ui->lineLogin->text() || user.getPassword() ==
                                                                ui->linePassword->text())
            {
                USER_NAME = ui->lineLogin->text();
                this->close();
                MainWindow *w = new MainWindow();
                w->show();
                break;
            }
            else if (stream.atEnd())
            {
                QMessageBox::warning(this, "", "Сheck that you have entered your login and password "
                                               "correctly or Sign In");
            }
        } while(!stream.atEnd());
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        file.close();
    }
}

///по нажатию кнопки Sign In, закрываем окно loginwindow и открываем окно signinwindow;
void loginwindow::on_buttonSignIn_clicked()
{
    this->close();
    signinwindow *w = new signinwindow();
    w->show();
}

