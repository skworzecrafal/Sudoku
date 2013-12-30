#ifndef PLANSZASAMURAJ_H
#define PLANSZASAMURAJ_H
#include "komorkas.h"
#include <QFrame>
#include <QWidget>

class PlanszaSamuraj:public QWidget
{
public:
    PlanszaSamuraj(QWidget *parent=0);
    ~PlanszaSamuraj();
    Komorkas tab[5][9][9];
    QFrame* linie[40];
    QWidget* pole;
    void zerujPola();

};

#endif // PLANSZASAMURAJ_H
