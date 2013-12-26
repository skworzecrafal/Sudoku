#ifndef PLANSZASAMURAJ_H
#define PLANSZASAMURAJ_H
#include "komorka.h"
#include <QFrame>
#include <QWidget>

class PlanszaSamuraj
{
public:
    PlanszaSamuraj(QWidget *parent);
    Komorka lg[9][9],rg[9][9],ld[9][9],rd[9][9],sr[9][9];
    QFrame* linie[40];
    QWidget* pole;
};

#endif // PLANSZASAMURAJ_H
