#include "message.h"

Message::Message()
{
    time = QTime::currentTime();
    name = "name";
    message = "message";
}

Message::Message(const QTime &new_time, const QString &new_name, const QString &new_message)
{
    time = new_time;
    name = new_name;
    message = new_message;
}

QTime Message::getTime() const
{
    return time;
}

QString Message::getName() const
{
    return name;
}

QString Message::getMessage() const
{
    return message;
}

void Message::setTime(const QTime &new_time)
{
    time = new_time;
}

void Message::setName(const QString &new_name)
{
    name = new_name;
}

void Message::setMessage(const QString &new_message)
{
    message = new_message;
}
