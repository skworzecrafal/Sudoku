#ifndef PLANSZA99_H
#define PLANSZA99_H
#include "komorka.h"
#include <QFrame>
#include <QWidget>


class Plansza99
{
public:
    Plansza99(QWidget *parent);
    ~Plansza99();
    Komorka plansza[9][9];
    QFrame* linie[8];
    QWidget* pole;

    void close();
    void show();
};

#endif // PLANSZA99_H
