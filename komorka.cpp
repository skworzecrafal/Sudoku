#include "komorka.h"

Komorka::Komorka()
{
    wartoscGra = new int();
    wartoscZnana = new int();
    *wartoscGra = *wartoscZnana = 0;
    pole = new QLineEdit();
    connect(pole,SIGNAL(editingFinished()),SLOT(ustaw()));
}

Komorka::Komorka(Komorka &wzor)
{
   pole = wzor.pole;
   wartoscGra = wzor.wartoscGra;
   wartoscZnana = wzor.wartoscZnana;
}

Komorka::~Komorka()
{
    delete pole;
    delete wartoscGra;
    delete wartoscZnana;
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

Komorka &Komorka::operator=(Komorka &K)
{
    wartoscGra = (K.wartoscGra);
    wartoscZnana = (K.wartoscZnana);
    return *this;
}

void Komorka::ustaw()
{
    *wartoscGra=pole->text().toInt();
    if (!(*wartoscGra))
        pole->setText("");
}

