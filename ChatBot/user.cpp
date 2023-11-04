
#include "user.h"

QString user::getName() const
{
    return name;
}

void user::setName(const QString &newName)
{
    name = newName;
}

QString user::getPassword() const
{
    return password;
}

void user::setPassword(const QString &newPassword)
{
    password = newPassword;
}

user::user()
{
    name = "user";
    password = "0000";
}

