
#include "message.h"

string path = "Data.txt";

message::message()
{
    T = 0;
    N = "NoName";
    M = "Empty";
}

void message::SetT(time_t T)
{
    this->T=T;
}

void message::SetN(string N)
{
    this->N=N;
}

void message::SetM(string M)
{
    this->M=M;
}

time_t message::GetT() const
{
    return T;
}

string message::GetN() const
{
    return N;
}

string message::GetM() const
{
    return M;
}

void message::Print()
{
    cout << T << "\t" << N << "\t" << M << endl;
}

void message::Write(message Message)
{
    ofstream fout;
    fout.open(path, ofstream::app);

    if (!fout.is_open())
    {
        cout << "error opening file" << endl;
    }
    else
    {
        cout << "file open" << endl;
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
        cout << "error opening file" << endl;
    }
    else
    {
        cout << "file open" << endl;
        while (fin.read((char*)&Message, sizeof(message)))
        {
            Message.Print();
        }
    }
    fin.close();
}

