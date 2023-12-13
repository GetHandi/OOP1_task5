
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

extern QString USER_NAME;
bool isEmpty = true;

void MainWindow::on_sendButton_clicked()
{
////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Если в поле сообщения пусто, ничего не происходит;
    if (ui->messageWindow->toPlainText() == ""){}
////////////////////////////////////////////////////////////////////////////////////////////////////
    else
    {
////////////////////////////////////////////////////////////////////////////////////////////////////
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



        QFile file ( MESSAGE_DATA );
        QDataStream stream ( &file );

        file.open( QIODevice::Append );

        stream << Message (message.getTime(), message.getName(), message.getMessage());
        stream << Message (message_bot.getTime(), message_bot.getName(), message_bot.getMessage());


        file.close();
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
    ///

////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
        QString dialog;
        if (isEmpty)
        {
            dialog = ui->messageWindow->toPlainText() + "\n\n" + message_bot.getMessage();
            isEmpty = false;
        }
        else
        {
            /// создаем экземпляр класса QString, в который добавляем текст из окна чата
            /// + текст из окна сообщения;
            dialog = (ui->chatWindow->toPlainText() + "\n\n" + ui->messageWindow->toPlainText()) + "\n\n" + message_bot.getMessage();
        }
////////////////////////////////////////////////////////////////////////////////////////////////////
        ///вывод в окно чата содержимое экземпляра класса QString;
        ui->chatWindow->setText(dialog);

    }
}

