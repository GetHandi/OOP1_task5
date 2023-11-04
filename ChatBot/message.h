
#ifndef MESSAGE_H
#define MESSAGE_H

#include <ctime>
#include <QString>
#include <QDebug>
#include <iostream>
#include <fstream>

using namespace std;



class message
{
    /// объекты класса T, N, M - время, имя, сообщение;
    time_t T;
    QString N, M;
public:
    ///конструктор по умолчанию;
    message();

    /// Метод для вывода в консоль данных записаных в класс;
    void Print();


    /// Метод записи класса в файл;
    void Write(message Message);

    /// Метод чтения класса из файла;
    void Read(message Message);

    /// Геттер для времени (не изменяет объекты);
    /// T - значение времени в секундах с 1970 года;
    time_t getT() const;

    /// Сеттер для времени;
    /// T - значение времени в секундах с 1970 года;
    void setT();

    /// Геттер для имени (не изменяет объекты);
    /// N - имя;
    QString getN() const;

    /// Сеттер для имени;
    /// N - имя;
    void setN(const QString &newN);

    /// Геттер для сообщения (не изменяет объекты);
    /// M - сообщение;
    QString getM() const;

    /// Сеттер для сообщения;
    /// M - сообщение;
    void setM(const QString &newM);
};

#endif // MESSAGE_H
