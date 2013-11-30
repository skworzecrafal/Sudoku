#ifndef GENERACJA_H
#define GENERACJA_H
#include <time.h>
#include <stdlib.h>

class Generacja
{
public:
    Generacja();
    void wiersz(int w, int** t);
    void kolumna(int k, int** t);
    void kwadrat(int w, int k, int** t);
    void generowanie(int tablica[9][9], int tabPelna[9][9], int ile);
};

#endif // GENERACJA_H
