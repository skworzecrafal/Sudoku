#include "dodajwynik.h"

DodajWynik::DodajWynik()
{
    okno = new QWidget();
    okno->setFixedSize(150,100);
    okno->setWindowTitle("");
    gracz = new QLineEdit(okno);
    gracz->setGeometry(20,10,110,30);
    gracz->setAlignment(Qt::AlignCenter);
    gracz->setText("Gracz");
    ok = new QPushButton(okno);
    ok->setGeometry(45,55,60,30);
    ok->setText("Potwierdź");
    gracz->selectAll();
}

void DodajWynik::dodaj(ListaWynikow lista[], int poziom, int min, int sek)
{
    Wynik* wynik;
    wynik = new Wynik();
    wynik->setImie(gracz->text());
    wynik->setMinuty(min);
    wynik->setSekundy(sek);
    lista[poziom - 1].dodaj(wynik);
}


