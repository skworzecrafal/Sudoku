#include "komorkas.h"

Komorkas::Komorkas()
{
    backupWart = new int;
}

Komorkas::~Komorkas()
{
    delete backupWart;
}

Komorkas &Komorkas::operator=(Komorkas &K)
{
    backupWart = K.backupWart;
    wartoscGra = K.wartoscGra;
    wartoscZnana = K.wartoscZnana;
    return *this;
}

void Komorkas::zeruj()
{
    *wartoscGra = 0;
    *wartoscZnana = 0;
    *backupWart = 0;
}
