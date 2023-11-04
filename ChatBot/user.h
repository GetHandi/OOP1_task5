
#ifndef USER_H
#define USER_H

#include <QString>
#include <QDebug>
#include <iostream>


class user
{
    /// объекты класса name - имя, password - пароль;
    QString name, password;
public:
    /// конструктор по умолчанию;
    user();

    /// Геттер для имени (не изменяет объекты);
    /// name - имя;
    QString getName() const;

    /// Сеттер для имени;
    /// name - имя;
    void setName(const QString &newName);

    /// Геттер для пароля (не изменяет объекты);
    /// password - пароль;
    QString getPassword() const;

    /// Сеттер для пароля;
    /// password - пароль;
    void setPassword(const QString &newPassword);
};

#endif // USER_H
