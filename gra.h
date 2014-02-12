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
#include "styltekstu.h"

class Gra:
        public Generacja,
        public StylTekstu
{
public:
    Gra(QWidget *parent=0);
    ~Gra();
    QTimer* zegar;
    Opcje o_opcje;
    DodajWynik o_dodajWynik;


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
    void zapiszConf();
    void resetWynikow();
    void podpowiedz(Komorka plansza[9][9]);
    void podpowiedz(Komorkas plansza[5][9][9]);
    int podpowiedz();
    void pomoc();
    int getSek() {return sek;}
    int getMin() {return min;}
    bool getKlasyczneOpen() {return klasyczneOpen;}
    bool getSamurajOpen() {return samurajOpen;}




private:
    ListaWynikow lista[4];
    OknoWyniki o_wyniki;
    Plansza99* klasyczne;
    PlanszaSamuraj* samuraj;
    QLabel* instrukcja;
    QLabel* inf_lpodp;

    int sek,min;
    bool klasyczneOpen;
    bool samurajOpen;
    bool opcjeOpen;
    bool wynikiOpen;
    bool isClickedCheck;
    bool pomocOpen;
    int wpisane,lPodpowiedzi;
};

#endif // GRA_H
