
#ifndef MESSAGE_H
#define MESSAGE_H

#include <ctime>
#include <string>

using namespace std;



class message
{
    /// объекты класса T, N, M - время, имя, сообщение;
    time_t T;
    string N, M;
public:
    ///конструктор по умолчанию;
    message();

    /// Сеттер для времени;
    /// T - значение времени в секундах с 1970 года;
    void SetT(time_t T);


    /// Сеттер для имени;
    /// N - имя;
    void SetN(string N);


    /// Сеттер для сообщения;
    /// M - сообщение;
    void SetM(string M);


    /// Геттер для времени (не изменяет объекты);
    /// T - значение времени в секундах с 1970 года;
    time_t GetT() const;


    /// Геттер для имени (не изменяет объекты);
    /// N - имя;
    string GetN() const;


    /// Геттер для сообщения (не изменяет объекты);
    /// M - сообщение;
    string GetM() const;
};

#endif // MESSAGE_H
