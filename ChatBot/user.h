
#ifndef USER_H
#define USER_H

#include <QDebug>
#include <QFile>
#include <QDataStream>


class User
{
private:
    /// объекты класса id - номер, login - имя, password - пароль;
    int id;
    QString login, password;


public:
    /// конструктор по умолчанию;
    User();

    /// конструктор;
    User(int new_id, const QString &new_login, const QString &new_password);

    /// Геттер для логина (не изменяет объекты);
    QString getLogin() const;

    /// Геттер для пароля (не изменяет объекты);
    QString getPassword() const;

    /// Геттер для номера (не изменяет объекты);
    int getId() const;

    /// Дружественная функция чтения из файла;
    friend QDataStream& operator>>( QDataStream& D, User& U );

    /// Дружественная функция записи в файл;
    friend QDataStream& operator<<( QDataStream& D, const User& U );
};

#endif // USER_H
