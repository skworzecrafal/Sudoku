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

    void zerujPola();

private:
    QFrame* linie[40];

};

#endif // PLANSZASAMURAJ_H
