#include "dodajwynik.h"

DodajWynik::DodajWynik()
{
    okno = new QWidget();
    okno->setFixedSize(150,150);
    okno->setWindowTitle(" ");
    etykieta = new QLabel(okno);
    etykieta->setAlignment(Qt::AlignCenter);
    etykieta->setText("Podaj swoje imię:");
    etykieta->setGeometry(5,10,140,30);
    etykieta->setStyleSheet("font: 75 12pt MS Shell Dlg 2;");
    gracz = new QLineEdit(okno);
    gracz->setGeometry(20,50,110,30);
    gracz->setAlignment(Qt::AlignCenter);
    gracz->setMaxLength(20);
    gracz->setText("Gracz");
    ok = new QPushButton(okno);
    ok->setGeometry(45,105,60,30);
    ok->setText("Potwierdź");
    gracz->selectAll();
}

DodajWynik::~DodajWynik()
{
    delete etykieta;
    delete gracz;
    delete ok;
    delete okno;
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


