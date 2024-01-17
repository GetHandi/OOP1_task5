
#ifndef PROCESSING_REQUEST_H
#define PROCESSING_REQUEST_H

#include <QNetworkAccessManager>


#include "message.h"


class Processing_request
{
public:
    Processing_request();
    QString request(Message message);

private slots:
    // Обработчик данных полученных от объекта QNetworkAccessManager;
    void onResult(QNetworkReply *reply);

private:

    QNetworkAccessManager *networkManager;

    QJsonObject readToJsonObject();

    void getJson(QString url);

    QString multiplication(QString message);

    QString division(QString message);

    QString sum(QString message);

    QString difference(QString message);

    QString currency(QString message);
};

#endif // PROCESSING_REQUEST_H
