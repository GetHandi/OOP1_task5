
#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QString USER_NAME;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    // Текст дефолтного сообщения чата с описанием его возможностей;
    message.setMessage("Привет, я чат-бот LUM! <br />Смотри что я умею:<br />"
                       "1) Показывать системное время (просто напиши в чат - время);<br />"
                       "2) ");/*todo: дописать*/

    // Добавление дефолтного сообщения бота в виджет чата;
    ui->chatWindow->append("<font color='green'><strong>" + CHAT_BOT_NAME +
                           "</strong></font><br />" + message.getMessage() +
                           "<br /><small>" + message.getTime().toString("hh:mm") +
                           "</small></background>"); /*todo: увеличить текст сообщения*/

    // Выравнивание сообщения бота по левой стороне;
    ui->chatWindow->setAlignment(Qt::AlignLeft);
}

// Деструктор;
MainWindow::~MainWindow(){
    delete ui;
}


// Обработка нажатия кнопки отправить сообщение;
void MainWindow::on_sendButton_clicked(){
    // Если поле сообщения не пусто;
    if (ui->messageWindow->toPlainText() != "")
    {
        message.setName(USER_NAME);    // Изменяем поле name экземпляра класса Message;
        message.setMessage(ui->messageWindow->toPlainText());    // Изменяем поле message экземпляра класса Message;
        message.setTime(QTime::currentTime());    // Изменяем поле time экземпляра класса Message;
        ui->messageWindow->clear();    // Очищаем виджет ввода сообщения пользователем;


        // Вывод сообщений пользователя в чат;
        ui->chatWindow->append("<font color='green'><strong>" + message.getName() + "</strong></font><br />"
                               + message.getMessage() + "<br />" + "<small>"
                               + message.getTime().toString("hh:mm") + "</small></background>");
        ui->chatWindow->setAlignment(Qt::AlignRight);


        message.setName(CHAT_BOT_NAME);
        message.setMessage(answer.request(message));
        message.setTime(QTime::currentTime());


        // Вывод сообщений бота в чат;
        ui->chatWindow->append("<font color='red'><strong>" + message.getName() + "</strong></font><br />"
                               + message.getMessage() + "<br />" + "<small>"
                               + message.getTime().toString("hh:mm") + "</small>");

        ui->chatWindow->setAlignment(Qt::AlignLeft);


        // Добавление полученных экземпляров класса Message в файл базы данных сообщение - "message_data.bin";
//        QFile file ( MESSAGE_DATA );
//        QDataStream stream ( &file );

//        file.open( QIODevice::Append );

//        stream << Message (message.getTime(), message_bot.getName(), message_bot.getMessage());

//        file.close();
    }

}



void MainWindow::on_messageWindow_textChanged()
{
    QString text = ui->messageWindow->toPlainText();
    if (text.contains("\n"))
    {
        // Вызов сигнала кнопки;
        ui->sendButton->click();
    }
}

