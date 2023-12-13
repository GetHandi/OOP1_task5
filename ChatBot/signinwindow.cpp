
#include "signinwindow.h"
#include "ui_signinwindow.h"

extern QString USER_NAME;

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
////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Если поля login и password пусты - ошибка;
    if (ui->lineLogin->text() == "" || ui->linePassword->text() == "")
    {
        QMessageBox::warning(this, "", "The login and password field cannot be empty");
    }
////////////////////////////////////////////////////////////////////////////////////////////////////
    else
    {
        User user;
        int lastId = 0;
        QFile file( USER_DATA );
        QDataStream stream( &file );
        file.open( QIODevice::ReadOnly );

////////////////////////////////////////////////////////////////////////////////////////////////////
        /// проверка login'a на совпадение и получение последнего id;
        while(!stream.atEnd())
        {
            stream >> user;
            lastId = user.getId();
            if (user.getLogin() == ui->lineLogin->text())
            {
                QMessageBox::warning(this, "", "User with this login already exists");
                lastId = -1;
                break;
            }
        }
////////////////////////////////////////////////////////////////////////////////////////////////////

        file.close();

////////////////////////////////////////////////////////////////////////////////////////////////////
        /// если login введнный пользователь не совпал с login'ами из файла, то присваиваем объекту
        /// класса данные последнего id+1 и данные из полей login и password и добавляем в файл;
        if (lastId != -1)
        {
            User userSignIn (lastId+1, ui->lineLogin->text(), ui->linePassword->text());
            QFile file( USER_DATA );
            QDataStream stream( &file );

            file.open( QIODevice::Append );

            stream << User (userSignIn.getId(), userSignIn.getLogin(), userSignIn.getPassword());

            file.close();

            this->close();

            USER_NAME = ui->lineLogin->text();

            MainWindow *w = new MainWindow();
            w->show();
        }
////////////////////////////////////////////////////////////////////////////////////////////////////
    }
}


