#ifndef PLANSZASAMURAJ_H
#define PLANSZASAMURAJ_H
#include "komorkas.h"
#include <QFrame>
#include <QWidget>

class PlanszaSamuraj
{
public:
    PlanszaSamuraj(QWidget *parent);
    Komorkas tab[5][9][9];
    QFrame* linie[40];
    QWidget* pole;
    void zerujPola();
    void close();
    void show();
};

#endif // PLANSZASAMURAJ_H
