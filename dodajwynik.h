#ifndef DODAJWYNIK_H
#define DODAJWYNIK_H
#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "listawynikow.h"
#include "wynik.h"

class DodajWynik: public QMainWindow
{
public:
    DodajWynik();
    QWidget* okno;
    QLineEdit* gracz;
    QPushButton* ok;
    void dodaj(ListaWynikow lista[],int poziom,int min,int sek);
};

#endif // DODAJWYNIK_H
