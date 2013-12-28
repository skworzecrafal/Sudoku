#include "komorka.h"

Komorka::Komorka()
{
    wartoscGra = new int();
    wartoscZnana = new int();
    *wartoscGra = *wartoscZnana = 0;
    pole = new QLineEdit();
    connect(pole,SIGNAL(editingFinished()),SLOT(ustaw()));
}


Komorka::~Komorka()
{
    delete pole;
    delete wartoscGra;
    delete wartoscZnana;
}

void Komorka::format(bool write, int rozm)
{
    if(write)
    {
        setStyl("Comic Sans MS",QPalette::Text,Qt::blue,rozm);
        pole->setPalette(paleta);
        pole->setFont(czcionka);
        pole->setReadOnly(false);
        pole->setAlignment(Qt::AlignCenter);
        pole->setMaxLength(1);
    }
    else
    {
        setStyl("Comic Sans MS",QPalette::Text,Qt::black,rozm);
        pole->setPalette(paleta);
        pole->setFont(czcionka);
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

