#include "wynik.h"

Wynik::Wynik()
{
    nastepny = NULL;
}

Wynik::~Wynik()
{
    delete nastepny;
}

void Wynik::setImie(QString imie)
{
    this->imie = imie;
}

void Wynik::setMinuty(int min)
{
    minuty = min;
}

void Wynik::setSekundy(int sek)
{
    sekundy = sek;
}

QString Wynik::getImie()
{
    return imie;
}
int Wynik::getMinuty()
{
    return minuty;
}
int Wynik::getSekundy()
{
    return sekundy;
}

