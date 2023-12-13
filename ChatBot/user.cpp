
#include "user.h"

User::User()
{
    id = 0;
    login = "login";
    password = "password";
}

User::User(int new_id, const QString &new_login, const QString &new_password)
{
    id = new_id;
    login = new_login;
    password = new_password;
}

QString User::getLogin() const
{
    return login;
}

QString User::getPassword() const
{
    return password;
}

int User::getId() const
{
    return id;
}

