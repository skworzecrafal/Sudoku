#ifndef GENERACJA_H
#define GENERACJA_H
#include <time.h>
#include <stdlib.h>
#include "komorkas.h"

class Generacja
{
public:
    Generacja();
    void wiersz(int w, int** t);
    void kolumna(int k, int** t);
    void kwadrat(int w, int k, int** t);
    void generowanie(Komorka plansza[9][9], int poziom=1);
    void poziomTrudnosci(Komorka plansza[9][9], int poziom=1);
    void generowanie(Komorkas plansza[5][9][9],int nr);
    void poziomTrudnosci(Komorkas plansza[5][9][9],int nr);
};

#endif // GENERACJA_H
