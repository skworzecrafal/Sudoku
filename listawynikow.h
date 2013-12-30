#ifndef LISTAWYNIKOW_H
#define LISTAWYNIKOW_H
#include "wynik.h"
#include <fstream>

class ListaWynikow
{
public:
    ListaWynikow();
    ~ListaWynikow();
    Wynik* pierwszy;
    Wynik* ostatni;
    int liczba;
    void wczytaj(char nazwa[]);
    void zapisz(char nazwa[]);
    void dodaj(Wynik * nowy);
};

#endif // LISTAWYNIKOW_H
