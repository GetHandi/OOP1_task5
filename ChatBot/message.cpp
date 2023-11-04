
#include "message.h"

string path = "Data.txt";

time_t message::getT() const
{
    return T;
}

void message::setT()
{
    time_t timeT;
    this->T = time(&timeT);
}

QString message::getN() const
{
    return N;
}

void message::setN(const QString &newN)
{
    N = newN;
}

QString message::getM() const
{
    return M;
}

void message::setM(const QString &newM)
{
    M = newM;
}

message::message()
{
    T = 0;
    N = "NoName";
    M = "Empty";
}

void message::Print()
{
    qInfo() << T << N << M;
}

void message::Write(message Message)
{
    ofstream fout;
    fout.open(path, ofstream::app);

    if (!fout.is_open())
    {
        qInfo() << "error opening file";
    }
    else
    {
        qInfo() << "file open";
        fout.write((char*)&Message, sizeof(message));
    }
    fout.close();
}

void message::Read(message Message)
{
    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        qInfo() << "error opening file";
    }
    else
    {
        qInfo() << "file open";
        while (fin.read((char*)&Message, sizeof(message)))
        {
            Message.Print();
        }
    }
    fin.close();
}

