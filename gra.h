#ifndef GRA_H
#define GRA_H

#include <QWidget>
#include "generacja.h"
#include <QTimer>
#include "opcje.h"
#include "listawynikow.h"
#include "oknowyniki.h"
#include "dodajwynik.h"
#include "plansza99.h"
#include "planszasamuraj.h"

class Gra:
        public Generacja
{
public:
    Gra();
    QTimer* zegar;
    Opcje o_opcje;
    DodajWynik o_dodajWynik;
    int sek,min;

    void wywolajKonstruktory(QWidget *parent=0);
    void wypisz(bool w);
    void wypisz(bool w, Komorkas plansza[5][9][9]);
    void generuj(int typ);
    void nowaGra();
    void opcje();
    void wyniki();
    void wyjscie();
    int sprawdz(Komorka plansza[9][9]);
    int sprawdz(Komorkas plansza[5][9][9]);
    int sprawdz();
    void czas();
    void dodWynik();
    void wczytajConf();
    void zapiszConf();


private:
    ListaWynikow lista[4];
    OknoWyniki o_wyniki;
    Plansza99* klasyczne;
    PlanszaSamuraj* samuraj;

    bool opcjeOpen;
    bool wynikiOpen;
    bool isClickedCheck;
    bool klasyczneOpen;
    bool samurajOpen;
    int wpisane;
};

#endif // GRA_H
