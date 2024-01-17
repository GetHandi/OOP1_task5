#include <QFile>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QJsonObject>
#include <QUrl>

#include "processing_request.h"
//#include "foo.cpp"

Processing_request::Processing_request()
{

}

QString Processing_request::request(Message message)
{
    // Добавление полученных экземпляров класса Message в файл базы данных сообщение - "*имя пользователя*_data.bin";
    QFile file ( message.getName() + "_data.bin" );
    QDataStream stream ( &file );
    file.open( QIODevice::Append );
    stream << Message (message.getTime(), message.getName(), message.getMessage());
    file.close();


    // Создаем переменную ответа для чат-бота с дефолтным содержимым, в случае не распознования сообщения от пользователя;
    QString answer = "Простите я Вас не понимаю, напишите /menu для просмотра моих возможностей";

    // Обработка приветствия;
    if (message.getMessage().toLower().contains("привет") || message.getMessage().toLower().contains("здравствуй"))
    {
        ///доработать, возможно через json
        answer = "Доброго времени суток, " + message.getName() + "!";
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
    return answer;
}

QJsonObject Processing_request::readToJsonObject(){
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



void Processing_request::getJson(QString url){
    networkManager = new QNetworkAccessManager();
//    QAbstractSocket::connect(networkManager, &QNetworkAccessManager::finished, this, &Processing_request::onResult);
//    // Подключаем networkManager к обработчику ответа;
//    networkManager->get(QNetworkRequest(QUrl(url)));    // Получаем данные, а именно JSON файл с сайта по определённому url;
}



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!пока оставим, если void MainWindow::getJson(QString url) все-таки делаять без лямбды!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Processing_request::onResult(QNetworkReply *reply){
    // Если ошибки отсутсвуют
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
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

QString Processing_request::multiplication(QString message){
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

QString Processing_request::division(QString message){
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

QString Processing_request::sum(QString message){
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

QString Processing_request::difference(QString message){
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

QString Processing_request::currency(QString message){
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

