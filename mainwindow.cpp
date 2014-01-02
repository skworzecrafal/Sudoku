#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),Gra(this)
{
    setFixedSize(1000,720);
    setGeometry(185,35,1000,720);
    stworzUi();

    /*
     *ustawienie akcji do buttonów
     */
    connect(o_opcje.reset,SIGNAL(clicked()),this,SLOT(reset_clicked()));
    connect(o_dodajWynik.ok,SIGNAL(clicked()),this,SLOT(nowyWynik()));
    connect(o_dodajWynik.gracz,SIGNAL(returnPressed()),this,SLOT(nowyWynik()));
    connect(przycisk[0],SIGNAL(clicked()),this,SLOT(nowaGra_clicked()));
    connect(przycisk[1],SIGNAL(clicked()),this,SLOT(opcje_clicked()));
    connect(przycisk[2],SIGNAL(clicked()),this,SLOT(wyniki_clicked()));
    connect(przycisk[3],SIGNAL(clicked()),this,SLOT(pomoc_clicked()));
    connect(przycisk[4],SIGNAL(clicked()),this,SLOT(wyjscie_clicked()));
    connect(przycisk[5],SIGNAL(clicked()),this,SLOT(Check_clicked()));
    connect(przycisk[6],SIGNAL(clicked()),this,SLOT(wskazowka()));
    connect(zegar,SIGNAL(timeout()),this,SLOT(zegarek()));
}

MainWindow::~MainWindow()
{
    for(int i=0;i<7;i++)
        delete przycisk[i];
    delete naglowek;
    delete zegarWyswietlacz;
    delete wynikGry;
}

void MainWindow::stworzUi()
{
    int i;
    for(i=0;i<7;i++)
        przycisk[i] = new QPushButton(this);
    naglowek = new QLabel(this);
    zegarWyswietlacz = new QLabel(this);
    wynikGry = new QLabel(this);

    naglowek->setGeometry(0,5,700,60);
    naglowek->setAlignment(Qt::AlignCenter);
    setStyl("Comic Sans MS",QPalette::Text,Qt::black,63);
    czcionka.setBold(true);
    naglowek->setPalette(paleta);
    naglowek->setFont(czcionka);
    naglowek->setText("S U D O K U");

    setStyl("Comic Sans MS",QPalette::ButtonText,Qt::black,20);
    for(i=0;i<5;i++)
    {
        przycisk[i]->setGeometry(850,i*60+20,140,50);
        przycisk[i]->setPalette(paleta);
        przycisk[i]->setFont(czcionka);
    }
    przycisk[0]->setText("Nowa Gra");
    przycisk[1]->setText("Opcje");
    przycisk[2]->setText("Wyniki");
    przycisk[3]->setText("Pomoc");
    przycisk[4]->setText("Wyjście");

    wynikGry->setGeometry(770,370,230,40);
    wynikGry->setAlignment(Qt::AlignCenter);
    setStyl("Comic Sans MS",QPalette::Text,Qt::black,20);
    czcionka.setBold(false);
    wynikGry->setPalette(paleta);
    wynikGry->setFont(czcionka);

    zegarWyswietlacz->setGeometry(760,480,240,40);
    zegarWyswietlacz->setAlignment(Qt::AlignLeft);
    setStyl("Comic Sans MS",QPalette::Text,Qt::black,30);
    zegarWyswietlacz->setPalette(paleta);
    zegarWyswietlacz->setFont(czcionka);
    zegarWyswietlacz->close();
    zegarWyswietlacz->setText("Czas gry:  "+QString::number(0)
                              +QString::number(0)+":"
                              +QString::number(0)+QString::number(0));


    setStyl("Comic Sans MS",QPalette::Text,Qt::black,15);
    przycisk[5]->setGeometry(800,430,200,30);
    przycisk[5]->setPalette(paleta);
    przycisk[5]->setFont(czcionka);
    przycisk[5]->setText("Sprawdź rozwiązanie");

    setStyl("Comic Sans MS",QPalette::Text,Qt::black,15);
    przycisk[6]->setGeometry(870,665,120,30);
    przycisk[6]->setPalette(paleta);
    przycisk[6]->setFont(czcionka);
    przycisk[6]->setText("Podpowiedź");
    przycisk[6]->setEnabled(false);
}

/*
 *  obsługa sygnału wydawanego przez zegar
 */
void MainWindow::zegarek()
{
    czas();
    zegarWyswietlacz->setText("Czas gry:  "+QString::number(min/10)
                               +QString::number(min%10)+":"
                               +QString::number(sek/10)+QString::number(sek%10));
}
/*
 *  obsługa nowej gry
 */
void MainWindow::nowaGra_clicked()
{
    zegarWyswietlacz->show();
    nowaGra();
    zegarWyswietlacz->setText("Czas gry:  "+QString::number(min/10)
                              +QString::number(min%10)+":"
                              +QString::number(sek/10)+QString::number(sek%10));
    wynikGry->setText("");
    przycisk[6]->setEnabled(true);
}

/*
 *otwiera okno opcji
 */

void MainWindow::opcje_clicked()
{
    opcje();
}
/*
 *sprawdza rozwiązanie
 */
void MainWindow::Check_clicked()
{
    int w = sprawdz();
    if(w<0)
    {
        wynikGry->setText("Może innym razem :(");
    }
    else
        if(w>0)
        {
            wynikGry->setText("Gratulacje!!! ;)");
        }
}

void MainWindow::wskazowka()
{
    if(!podpowiedz())
    {
       przycisk[6]->setEnabled(false);
    }
}

/*
 *wyjście z programu i zapisanie listy wyników do plików
 */
void MainWindow::wyjscie_clicked()
{
    wyjscie();
    close();
}

/*
 *otwarcie okna z listą wyników
 */
void MainWindow::wyniki_clicked()
{
    wyniki();
}
/*
 *reset listy wyników
 */
void MainWindow::reset_clicked()
{
    resetWynikow();
}
/*
 *slot dodania nowego wyniku
 */
void MainWindow::nowyWynik()
{
    dodWynik();
}

void MainWindow::pomoc_clicked()
{
    pomoc();
}
