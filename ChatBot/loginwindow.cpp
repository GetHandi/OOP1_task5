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

// Обработка нажатия кнопки Авторизироваться;
void loginwindow::on_buttonLogIn_clicked()
{
    /// Если поля login и password пусты - ошибка;
    if (ui->lineLogin->text() == "" || ui->linePassword->text() == "")
    {
        QMessageBox::warning(this, "", "Поля логин/пароль не могут быть пустыми");
    }
    else
    {
        User user;
        QFile file( USER_DATA );
        QDataStream stream( &file );
        file.open( QIODevice::ReadOnly );

        /// проверка login'a на совпадение и получение последнего id;
        do {
            stream >> user;
            if (user.getLogin() == ui->lineLogin->text() || user.getPassword() ==
                                                                ui->linePassword->text())
            {
                USER_NAME = ui->lineLogin->text();
                this->close();
                MainWindow *w = new MainWindow();
                w->setWindowTitle("Чат-бот LUM");
                w->show();
                break;
            }
            else if (stream.atEnd())
            {
                QMessageBox::warning(this, "", "Данная пара логин/пароль не зарегистрирована, "
                                               "проверьте корректность введенных Вами данных, "
                                               "либо зарегистрируйтесь нажав кнопку \"Регистрация\"");
            }
        } while(!stream.atEnd());

        file.close();
    }
}

// Обработка нажатия кнопки Зарегистрироваться;
void loginwindow::on_buttonSignIn_clicked()
{
    // Если поля login и password пусты - ошибка;
    if (ui->lineLogin->text() == "" || ui->linePassword->text() == "")
    {
        QMessageBox::warning(this, "", "Поля логин/пароль не могут быть пустыми");
    }
    // Иначе;
    else
    {
        User user;
        int lastId = 0;
        QFile file( USER_DATA );
        QDataStream stream( &file );
        file.open( QIODevice::ReadOnly );

        // проверка login'a на совпадение и получение последнего id;
        while(!stream.atEnd())
        {
            stream >> user;
            lastId = user.getId();
            if (user.getLogin() == ui->lineLogin->text())
            {
                QMessageBox::warning(this, "", "Пользователь с таким именем уже зарегистрирован");
                lastId = -1;
                break;
            }
        }

        file.close();

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
            w->setWindowTitle("Чат-бот LUM");
            w->show();
        }
    }
}

