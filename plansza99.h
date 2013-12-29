#ifndef PLANSZA99_H
#define PLANSZA99_H
#include "komorka.h"
#include <QFrame>
#include <QWidget>


class Plansza99: public QWidget
{
public:
    Plansza99(QWidget *parent);
    ~Plansza99();
    Komorka plansza[9][9];
    QFrame* linie[8];

};

#endif // PLANSZA99_H
