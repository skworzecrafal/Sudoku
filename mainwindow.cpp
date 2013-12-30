#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setFixedSize(1000,720);
    setGeometry(185,35,1000,720);
    stworzUi();
    wczytajConf();
    wywolajKonstruktory(this);

    /*
     *ustawienie akcji do buttonów
     */
//    connect(oknoOpcje.easy,SIGNAL(clicked()),SLOT(easy_clicked()));
//    connect(oknoOpcje.medium,SIGNAL(clicked()),this,SLOT(medium_clicked()));
//    connect(oknoOpcje.hard,SIGNAL(clicked()),this,SLOT(hard_clicked()));
//    connect(oknoOpcje.reset,SIGNAL(clicked()),this,SLOT(resetWynikow()));
    connect(o_dodajWynik.ok,SIGNAL(clicked()),this,SLOT(nowyWynik()));
    connect(o_dodajWynik.gracz,SIGNAL(returnPressed()),this,SLOT(nowyWynik()));
    connect(przycisk[4],SIGNAL(clicked()),this,SLOT(wyjscie_clicked()));
    connect(przycisk[0],SIGNAL(clicked()),this,SLOT(nowaGra_clicked()));
    connect(zegar,SIGNAL(timeout()),this,SLOT(zegarek()));
    connect(przycisk[1],SIGNAL(clicked()),this,SLOT(opcje_clicked()));
    connect(przycisk[5],SIGNAL(clicked()),this,SLOT(Check_clicked()));
    connect(przycisk[2],SIGNAL(clicked()),this,SLOT(wyniki_clicked()));
}

MainWindow::~MainWindow()
{
    for(int i=0;i<8;i++)
        delete przycisk[i];
    delete naglowek;
    delete zegarWyswietlacz;
    delete wynikGry;
}

void MainWindow::stworzUi()
{
    int i;
    for(i=0;i<8;i++)
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

    zegarWyswietlacz->setGeometry(770,480,230,40);
    zegarWyswietlacz->setAlignment(Qt::AlignLeft);
    setStyl("MS Shell",QPalette::Text,Qt::black,30);
    zegarWyswietlacz->setPalette(paleta);
    zegarWyswietlacz->setFont(czcionka);
    zegarWyswietlacz->setText("Czas gry:  "+QString::number(0)
                              +QString::number(0)+":"
                              +QString::number(0)+QString::number(0));

    setStyl("Comic Sans MS",QPalette::Text,Qt::black,15);
    przycisk[5]->setGeometry(800,430,200,30);
    przycisk[5]->setPalette(paleta);
    przycisk[5]->setFont(czcionka);
    przycisk[5]->setText("Sprawdź rozwiązanie");

    setStyl("Comic Sans MS",QPalette::Text,Qt::black,10);
    for(i=6;i<8;i++)
    {
        przycisk[i]->setGeometry(920,(i-6)*25+665,70,20);
        przycisk[i]->setPalette(paleta);
        przycisk[i]->setFont(czcionka);
    }
    przycisk[6]->setText("1 cyfra");
    przycisk[7]->setText("wszystkie");
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
    nowaGra();
    zegarWyswietlacz->setText("Czas gry:  "+QString::number(min/10)
                              +QString::number(min%10)+":"
                              +QString::number(sek/10)+QString::number(sek%10));
    wynikGry->setText("");
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

//void MainWindow::on_pomoc_clicked()
//{
//    int tabl[9][9],tab1[81];
//    int w,k,wsp,rozm=0;
//    srand(time(NULL));
//    for(w=0;w<9;w++)
//        for(k=0;k<9;k++)
//        {
//            tabl[w][k]=w*10+k;

//        }
//    for(w=0;w<9;w++)
//        for(k=0;k<9;k++)
//        {
//            if(!*plansza99->plansza[w][k].wartoscGra)
//            {
//                tab1[rozm]=tabl[w][k];
//                rozm++;
//            }

//        }
//    if(rozm)
//    {
//        wsp = rand() % rozm;
//        w = tab1[wsp]/10;
//        k = tab1[wsp] % 10;
//        plansza99->plansza[w][k].pole->setText(QString::number(*plansza99->plansza[w][k].wartoscZnana));
//        plansza99->plansza[w][k].pole->editingFinished();
//    }
//}

//void MainWindow::on_pomoc_2_clicked()
//{

//    for(int w=0;w<9;w++)
//        for(int k=0;k<9;k++)
//        {
//            plansza99->plansza[w][k].pole->setText(QString::number(*plansza99->plansza[w][k].wartoscZnana));
//            plansza99->plansza[w][k].pole->editingFinished();
//        }
//}
/*
 *wyjście z programu i zapisanie listy wyników do plików
 */
void MainWindow::wyjscie_clicked()
{
    wyjscie();
    close();
}
///*
// * poziom łatwy
// */
//void MainWindow::easy_clicked()
//{
//    min = sek = 0;
//    zegar->stop();
//    if(plansza99Open)
//        plansza99->close();
//    if(samurajOpen)
//        samuraj->close();
//}
///*
// *poziom średni
// */
//void MainWindow::medium_clicked()
//{
//    min = sek = 0;
//    zegar->stop();
//    if(plansza99Open)
//        plansza99->close();
//    if(samurajOpen)
//        samuraj->close();
//}
///*
// *poziom trudny
// */
//void MainWindow::hard_clicked()
//{
//    min = sek = 0;
//    zegar->stop();
//    if(plansza99Open)
//        plansza99->close();
//    if(samurajOpen)
//        samuraj->close();
//}
/*
 *otwarcie okna z listą wyników
 */
void MainWindow::wyniki_clicked()
{
    wyniki();
}
///*
// *reset listy wyników
// */
//void MainWindow::resetWynikow()
//{
//    for(int i=0;i<4;i++)
//        lista[i].~ListaWynikow();
//}
///*
// *slot dodania nowego wyniku
// */
void MainWindow::nowyWynik()
{
    dodWynik();
}
