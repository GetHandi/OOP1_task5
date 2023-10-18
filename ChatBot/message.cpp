
#include "message.h"

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

