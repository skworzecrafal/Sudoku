#include "komorka.h"
#include <QColor>

Komorka::Komorka()
{
    wartoscGra = wartoscZnana = 0;
}

void Komorka::format(bool write)
{
    if(write)
    {
        pole->setStyleSheet("font: 24pt Comic Sans MS;"
                           "color: rgb(0, 180, 0)");
        pole->setReadOnly(false);
        pole->setAlignment(Qt::AlignCenter);
        pole->setMaxLength(1);
    }
    else
    {
        pole->setStyleSheet("font: 75 24pt Comic Sans MS;"
                           "color: rgb(0, 0, 0)");
        pole->setReadOnly(true);
        pole->setAlignment(Qt::AlignCenter);
        pole->setMaxLength(1);
    }
}

