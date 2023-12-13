#include "message.h"

Message::Message()
{
    time = "00:00";
    name = "name";
    message = "message";
}

Message::Message(const QString &new_time, const QString &new_name, const QString &new_message)
{
    time = new_time;
    name = new_name;
    message = new_message;
}

QString Message::getTime() const
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

void Message::setMessage(const QString &new_message)
{
    message = new_message;
}
