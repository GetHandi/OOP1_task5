
#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QTime>

using namespace std;

class Message
{
private:
    /// объекты класса time, name, message - время, имя, сообщение;
    QTime time;
    QString name, message;


public:
    Message();    /// конструктор по умолчанию;

    Message(const QTime &new_time, const QString &new_name, const QString &new_message);    /// конструктор;

    QTime getTime() const;    /// Геттер для времени (не изменяет объекты);

    QString getName() const;    /// Геттер для имени (не изменяет объекты);

    QString getMessage() const;    /// Геттер для сообщения (не изменяет объекты);

    void setTime (const QTime &new_time);    /// Сеттер для сообщения;

    void setName(const QString &new_name);    /// Сеттер для сообщения;

    void setMessage(const QString &new_message);    /// Сеттер для сообщения;

    friend QDataStream& operator>>( QDataStream& D, Message& M );    /// Дружественная функция чтения из файла;

    friend QDataStream& operator<<( QDataStream& D, const Message& M );    /// Дружественная функция записи в файл;
};

#endif // MESSAGE_H
