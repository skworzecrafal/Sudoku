
#pragma once
#include "generacja.h"
class Plansza

{
public:
    Plansza(void);
    int tablica[9][9];
    int tabPelna[9][9];
    void Wczytaj(int w, int k, int liczba);
    void Czysc();

};


