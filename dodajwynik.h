#ifndef DODAJWYNIK_H
#define DODAJWYNIK_H
#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "listawynikow.h"
#include "wynik.h"

class DodajWynik: public QMainWindow
{
public:
    DodajWynik();
    ~DodajWynik();
    QWidget* okno;
    QLineEdit* gracz;
    QPushButton* ok;
    QLabel* etykieta;
    void dodaj(ListaWynikow lista[],int karta,int min,int sek);
};

#endif // DODAJWYNIK_H
