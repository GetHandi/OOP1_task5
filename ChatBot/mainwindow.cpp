
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //прописать автоотправку сообщения с меню или с приветствием;

}

MainWindow::~MainWindow()
{
    delete ui;
}

extern QString USER_NAME;

// стилистика вывода сообщений от бота и пользователя;
// "<hr>" - отделяет следующую запись чертой, ставится в конце.
// "<p>" "</p>" - определяет абзац в тексте. Друг от друга абзацы отделяются пустой строкой.
// <p align="left">Текст</p> - Выравнивание по левому краю.
// <p align="right">Текст</p> - Выравнивание по правому краю.
// "<br />" - устанавливает перевод строки, то есть все написанное после него, будет перенесено на новую строку.
// <small> </small> - определяет размер шрифта текста на один размер меньше, чем у родительского элемента
// <strong> </strong> - жирный

void MainWindow::on_sendButton_clicked()
{
    // Если в поле сообщения пусто, ничего не происходит;
    if (ui->messageWindow->toPlainText() == ""){}
    // Иначе
    else
    {
        // Создание экземпляра класса Message - сообщение пользователя {время отправки сообщения,
        // имя пользователя указанное при авторизации, сообщение, введенное пользователем};
        Message message (QTime::currentTime(), USER_NAME, ui->messageWindow->toPlainText());

        // очищаем виджет messageWindow;
        ui->messageWindow->clear();

        // Вывод сообщений пользователя в чат;

        ui->chatWindow->append("<font color='brown'><strong>" + message.getName() + "</strong></font><br />" + message.getMessage() + "<br />"
                               + "<small>" + message.getTime().toString("hh:mm") + "</small>");
        ui->chatWindow->setAlignment(Qt::AlignRight);
        // Реализация ответа бота;
        QString answer = "тестовый ответ";

        // Создание экземпляра класса Message - сообщение бота {время отправки сообщения,
        // имя пользователя - имя бота, сообщение, введенное пользователем};
        Message message_bot (QTime::currentTime(), CHAT_BOT_NAME, answer);

        // Вывод сообщений бота в чат;
        ui->chatWindow->append("<font color='brown'><strong>" + message_bot.getName() + "</strong></font><br />" + message_bot.getMessage() + "<br />"
                               + "<small>" + message_bot.getTime().toString("hh:mm") + "</small>");
        ui->chatWindow->setAlignment(Qt::AlignLeft);

        // Добавление полученных экземпляров класса Message в файл базы данных сообщение - "message_data.bin";
        QFile file ( MESSAGE_DATA );
        QDataStream stream ( &file );

        file.open( QIODevice::Append );

        stream << Message (message.getTime(), message.getName(), message.getMessage());
        stream << Message (message.getTime(), message_bot.getName(), message_bot.getMessage());

        file.close();



    }


        /*


        ///создаем объект класса Message, добавляем в него данные и записываем в файл;
        Message message (QTime::currentTime().toString("hh:mm:ss"), USER_NAME, ui->messageWindow->toPlainText());

        srand(time(0));
        int a = rand()%3;
        QString answer;

        Message message_bot (QTime::currentTime().toString("hh:mm:ss"), CHAT_BOT_NAME, "answer");
        if (message.getMessage().contains("ривет") || message.getMessage().contains("дравствуй"))
        {
            if (a == 0) answer = "Привет, ";
            else if (a == 1) answer = "Здравствуй, ";
            else answer = "Доброго времени суток, ";
            message_bot.setMessage(answer + USER_NAME + "!");
        }

        else if (message.getMessage().contains("дела"))
        {
            if (a == 0) answer = "Отлично";
            else if (a == 1) answer = "Нормально";
            else answer = "Здорово";
            message_bot.setMessage(answer);
        }
        else if (message.getMessage().contains("врем") || message.getMessage().contains("час"))
            message_bot.setMessage("Текущее время вашей системы: " + QTime::currentTime().toString("hh:mm"));

        else if (message.getMessage().contains("умножить"))
            message_bot.setMessage("Текущее время системы: " + QTime::currentTime().toString("hh:mm"));
        */



}

/*
Вывод в конcоль данных из файла message_data.bin
Message test;
int a = 1;
QFile file ( MESSAGE_DATA );
QDataStream stream ( &file );
file.open( QIODevice::ReadOnly );

while(!stream.atEnd())
{
    stream >> test;
    qInfo() << a << "\t" << test.getTime().toString("hh:mm:ss") << "\t" << test.getName() << "\t" << test.getMessage() << "\n";
    a++;
}

file.close();
*/

