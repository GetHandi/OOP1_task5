
#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QString USER_NAME;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /// возможно прописать автоотправку сообщения с меню или с приветствием;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// стилистика вывода сообщений от бота и пользователя;
// "<hr>" - отделяет следующую запись чертой, ставится в конце.
// "<p>" "</p>" - определяет абзац в тексте. Друг от друга абзацы отделяются пустой строкой.
// <p align="left">Текст</p> - Выравнивание по левому краю.
// <p align="right">Текст</p> - Выравнивание по правому краю.
// "<br />" - устанавливает перевод строки, то есть все написанное после него, будет перенесено на новую строку.
// <small> </small> - определяет размер шрифта текста на один размер меньше, чем у родительского элемента
// <strong> </strong> - жирный

// Обработка нажатия кнопки отправить сообщение;
void MainWindow::on_sendButton_clicked()
{
    ui->sendButton->setAttribute(Qt::WA_InputMethodEnabled);

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
        ui->chatWindow->append("<font color='green'><strong>" + message.getName() + "</strong></font><br />"
                               + message.getMessage() + "<br />" + "<small>"
                               + message.getTime().toString("hh:mm") + "</small></background>");
        ui->chatWindow->setAlignment(Qt::AlignRight);

        // Реализация ответа бота;


        /*
         * getJson("https://www.cbr-xml-daily.ru/daily_json.js");
         * QJsonObject root = readToJsonObject();
         * ui->chatWindow->append(root.keys().at(0) + ": " + root.value(root.keys().at(0)).toString());
        */

        // Создаем переменную ответа для чат-бота с дефолтным содержимым, в случае не распознования сообщения от пользователя;
        QString answer = "Простите я Вас не понимаю, напишите /menu для просмотра моих возможностей";

        // Обработка приветствия;
        if (message.getMessage().toLower().contains("привет") || message.getMessage().toLower().contains("здравствуй"))
        {
            ///доработать, возможно через json
            answer = "Доброго времени суток, " + USER_NAME + "!";
        }

        // Обработка фразы что ты можешь;
        else if (message.getMessage().toLower().contains("что ты можешь"))
        {
            answer = "Я могу подсказать системное время, курс валюты, погоду, "
                     "выполнить простейшие математические операции (сложение, вычитание, деление, умножение) <br />"
                     "для удобства ты можешь написать в чат команду /menu и узнать что я могу";

        }

        // Вывод прописанных команд меню;
        else if (message.getMessage().toLower().contains("/menu"))
        {
            answer = "<br />/время<br />/курс_валюты<br />/погода<br />/калькулятор";
        }

        // Инструкция время;
        else if ((message.getMessage().toLower().contains("/время")))
        {
            answer = "системное время: " + QTime::currentTime().toString("HH:mm:ss") +
                                           ", в будущем, можете просто написать: \"время\", я Вас пойму";
        }

        // Время;
        else if (message.getMessage().toLower() == "время")
        {
            answer = "системное время: " + QTime::currentTime().toString("HH:mm:ss");
        }

        // Инструкция курс валюты;
        else if (message.getMessage().toLower().contains("/курс_валюты"))
        {
            answer = "Для получения курсе валюты в рублях, напиши в чат сообщение c отражением количества "
                     "и наименования валюты. Например: /курс 10 Доллар США или /курс 10 USD";
        }

        // Курс валюты
        else if (message.getMessage().toLower().contains("/курс "))
        {

            QString str = message.getMessage().toLower();
            answer = currency(str);
        }

        else if (message.getMessage().toLower().contains("/погода"))
        {
            answer = "в разработке";
        }

        // Инструкция по калькулятору;
        else if (message.getMessage().toLower().contains("/калькулятор"))
        {
            answer = "Вы можете просто написать наименование операции и числа, например: "
                     "умножь 2 на 1.5 или раздели 7 на 15 и на 25.5";
        }

        // Обработка простыхх математических выражений;
        // Умножение;
        else if (message.getMessage().toLower().contains("умнож"))
        {
            QString str = message.getMessage();
            answer = multiplication(str);
        }

        // Деление;
        else if (message.getMessage().toLower().contains("раздели"))
        {
            QString str = message.getMessage();
            answer = division(str);
        }

        // Сумма;
        else if (message.getMessage().toLower().contains("cумма")
                 || message.getMessage().toLower().contains("сложи"))
        {
            QString str = message.getMessage();
            answer = sum(str);
        }

        // Разность;
        else if (message.getMessage().toLower().contains("вычти")
                 || message.getMessage().toLower().contains("разница"))
        {
            QString str = message.getMessage();
            answer = difference(str);
        }





        // Создание экземпляра класса Message - сообщение бота {время отправки сообщения,
        // имя пользователя - имя бота, сообщение, введенное пользователем};
        Message message_bot (QTime::currentTime(), CHAT_BOT_NAME, answer);

        // Вывод сообщений бота в чат;
        ui->chatWindow->append("<font color='red'><strong>" + message_bot.getName() + "</strong></font><br />"
                               + message_bot.getMessage() + "<br />" + "<small>"
                               + message_bot.getTime().toString("hh:mm") + "</small>");

        ui->chatWindow->setAlignment(Qt::AlignLeft);


        // Добавление полученных экземпляров класса Message в файл базы данных сообщение - "message_data.bin";
        QFile file ( MESSAGE_DATA );
        QDataStream stream ( &file );

        file.open( QIODevice::Append );

        stream << Message (message.getTime(), message.getName(), message.getMessage());
        stream << Message (message.getTime(), message_bot.getName(), message_bot.getMessage());

        file.close();
    }
}

void MainWindow::getJson(QString url)
{
    networkManager = new QNetworkAccessManager();

    // Подключаем networkManager к обработчику ответа
    connect(networkManager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if(!reply->error()){

            // Cоздаём объект Json Document, считав в него все данные из ответа
            QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
            QString jsonString = document.toJson(QJsonDocument::Indented);
//            // Забираем из документа корневой объект
//            QJsonObject root  = document.object();

            QFile file;
            file.setFileName("json.json");
            file.open( QIODevice::WriteOnly | QIODevice::Text );
            QTextStream stream( &file );
            stream << jsonString;
            file.close();
        }
        reply->deleteLater();
    } ); //&MainWindow::onResult
    // Получаем данные, а именно JSON файл с сайта по определённому url
    networkManager->get(QNetworkRequest(QUrl(url)));
}

QString MainWindow::multiplication(QString message)
{
    QStringList strList = message.split(QRegularExpression("\\s+"));
    double result = 1;
    bool ok;
    for ( const auto& i : strList )
    {
        double a = i.toDouble(&ok);
        if (ok)
        {
            result *= a;
        }
    }
    QString answer = QString::number(result);
    return answer;
}

QString MainWindow::division(QString message)
{
    QStringList strList = message.split(QRegularExpression("\\s+"));
    double result;
    bool ok;
    bool firstNum;
    for ( const auto& i : strList )
    {
        double a = i.toDouble(&ok);

        if (ok)
        {
            if (firstNum)
            {
                result = a;
                firstNum = false;
                continue;
            }
            result /= a;
        }
    }
    QString answer = QString::number(result);
    return answer;
}

QString MainWindow::sum(QString message)
{
    QStringList strList = message.split(QRegularExpression("\\s+"));
    double result = 0;
    bool ok;
    for ( const auto& i : strList )
    {
        double a = i.toDouble(&ok);
        if (ok)
        {
            result += a;
        }
    }
    QString answer = QString::number(result);
    return answer;
}

QString MainWindow::difference(QString message)
{
    QStringList strList = message.split(QRegularExpression("\\s+"));
    double result;
    bool ok;
    bool firstNum;
    for ( const auto& i : strList )
    {
        double a = i.toDouble(&ok);

        if (ok)
        {
            if (firstNum)
            {
                result = a;
                firstNum = false;
                continue;
            }
            result -= a;
        }
    }
    QString answer = QString::number(result);
    return answer;
}

QString MainWindow::currency(QString message)
{
    getJson("https://www.cbr-xml-daily.ru/daily_json.js");
    QJsonObject root = readToJsonObject();

    // Разбиваем сообщение пользователя по пробелам и сколько валюты нужно перевести в рубли;
    QStringList strList = message.split(QRegularExpression("\\s+"));
    double result;
    bool ok;
    for ( const auto& i : strList ) {
        double a = i.toDouble(&ok);
        if (ok) result = a;
    }

    // Получение объекта Valute;
    QJsonObject valuteObj = root.value("Valute").toObject();
    // Итерируем объект Valute по элементам;
    for (auto it = valuteObj.begin(); it != valuteObj.end(); ++it) {
        // Присваиваем переменной currencyObj значение элемента объекта Valute;
        QJsonObject currencyObj = it.value().toObject();
        // Если значение ключа Name или CharCode содержится в сообщении пользователя, то вычисляем курс;
        if (message.contains(currencyObj.value("Name").toString().toLower()) || message.contains(currencyObj.value("CharCode").toString().toLower()))
        {
            return QString::number(result / currencyObj.value("Nominal").toDouble() * currencyObj.value("Value").toDouble());
        }

    }
    return "проверьте правильность введенных данных";
}

// /курс 10 Доллар США
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!пока оставим, если void MainWindow::getJson(QString url) все-таки делаять без лямбды!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void MainWindow::onResult(QNetworkReply *reply)
{

    // Если ошибки отсутсвуют
    if(!reply->error()){

        // Cоздаём объект Json Document, считав в него все данные из ответа
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

        // Забираем из документа корневой объект
        QJsonObject root  = document.object();
        //ui->chatWindow->append(root.keys().at(0) + ": " + root.value(root.keys().at(0)).toString());

    }
    reply->deleteLater();
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

QJsonObject MainWindow::readToJsonObject()
{
    // Читаем файл .json в QString;
    QString val;
    QFile file( "json.json" );
    QTextStream stream( &file );
    file.open( QIODevice::ReadOnly );
    val = file.readAll();
    file.close();
    // Получаем объект;
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject root = doc.object();
    return root;
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


void MainWindow::on_messageWindow_textChanged()
{
    QString text = ui->messageWindow->toPlainText();
    if (text.contains("\n"))
    {
        // Вызов сигнала кнопки;
        ui->sendButton->click();
    }
}

