
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
    /// конструктор по умолчанию;
    Message();

    /// конструктор;
    Message(const QTime &new_time, const QString &new_name, const QString &new_message);

    /// Геттер для времени (не изменяет объекты);
    QTime getTime() const;

    /// Геттер для имени (не изменяет объекты);
    QString getName() const;

    /// Геттер для сообщения (не изменяет объекты);
    QString getMessage() const;

    /// Сеттер для сообщения;
    void setMessage(const QString &new_message);

    /// Дружественная функция чтения из файла;
    friend QDataStream& operator>>( QDataStream& D, Message& M );

    /// Дружественная функция записи в файл;
    friend QDataStream& operator<<( QDataStream& D, const Message& M );
};

#endif // MESSAGE_H
