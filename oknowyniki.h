#ifndef OKNOWYNIKI_H
#define OKNOWYNIKI_H
#include <QTabWidget>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include "listawynikow.h"
#include "wynik.h"
#include "styltekstu.h"

class OknoWyniki:
        public QMainWindow,
        public StylTekstu
{
public:
    OknoWyniki();
    ~OknoWyniki();


    void wypisz(ListaWynikow lista[]);
    void zamknij();

private:
    QTabWidget* oknoWyniki;
    QWidget* poziom[4];
    QLabel* label[4][10][3]; // 0 - easy; 1 - medium; 2 - hard; 3 - samuraj;
    QLabel* info[4][2];
    int liczba[4];
};

#endif // OKNOWYNIKI_H
