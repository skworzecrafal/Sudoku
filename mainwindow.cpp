#include "mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),Gra(this)
{
    setFixedSize(1000,720);
    setGeometry(185,35,1000,720);
    stworzUi();

    czekaj = new QTimer(this);
    czekaj->stop();

    czekanie = new QTimer(this);
    czekanie->stop();
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
    connect(czekaj,SIGNAL(timeout()),this,SLOT(czysc_wynik()));
    connect(play,SIGNAL(clicked()),this,SLOT(wlacz()));
    connect(stop,SIGNAL(clicked()),this,SLOT(wylacz()));
    connect(czekanie,SIGNAL(timeout()),this,SLOT(poczekaniu()));

    webview = new QWebView();
    webview->settings()->setAttribute(QWebSettings::PluginsEnabled,true);



}

MainWindow::~MainWindow()
{
    for(int i=0;i<7;i++)
        delete przycisk[i];
    delete naglowek;
    delete zegarWyswietlacz;
    delete wynikGry;
    delete play;
    delete stop;
    delete radio;
    delete webview;
}

void MainWindow::stworzUi()
{
    int i;
    for(i=0;i<7;i++)
        przycisk[i] = new QPushButton(this);
    naglowek = new QLabel(this);
    zegarWyswietlacz = new QLabel(this);
    wynikGry = new QLabel(this);
    radio = new QLabel(this);
    play = new QPushButton(this);
    stop = new QPushButton(this);

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

    wynikGry->setGeometry(770,320,230,40);
    wynikGry->setAlignment(Qt::AlignCenter);
    setStyl("Comic Sans MS",QPalette::Text,Qt::black,20);
    czcionka.setBold(false);
    wynikGry->setPalette(paleta);
    wynikGry->setFont(czcionka);

    zegarWyswietlacz->setGeometry(760,430,240,40);
    zegarWyswietlacz->setAlignment(Qt::AlignLeft);
    setStyl("Comic Sans MS",QPalette::Text,Qt::black,30);
    zegarWyswietlacz->setPalette(paleta);
    zegarWyswietlacz->setFont(czcionka);
    zegarWyswietlacz->close();
    zegarWyswietlacz->setText("Czas gry:  "+QString::number(0)
                              +QString::number(0)+":"
                              +QString::number(0)+QString::number(0));

    setStyl("Comic Sans MS",QPalette::Text,Qt::black,25);
    radio->setGeometry(760,525,240,40);
    radio->setAlignment(Qt::AlignCenter);
    radio->setPalette(paleta);
    radio->setFont(czcionka);
    radio->setText("Radio RMF MAXXX");


    setStyl("Comic Sans MS",QPalette::Text,Qt::black,15);
    przycisk[5]->setGeometry(800,380,190,30);
    przycisk[5]->setPalette(paleta);
    przycisk[5]->setFont(czcionka);
    przycisk[5]->setText("Sprawdź rozwiązanie");

    przycisk[6]->setGeometry(870,665,120,30);
    przycisk[6]->setPalette(paleta);
    przycisk[6]->setFont(czcionka);
    przycisk[6]->setText("Podpowiedź");
    przycisk[6]->setEnabled(false);

    play->setGeometry(770,575,105,30);
    play->setPalette(paleta);
    play->setFont(czcionka);
    play->setText("Włącz");

    stop->setGeometry(885,575,105,30);
    stop->setPalette(paleta);
    stop->setFont(czcionka);
    stop->setText("Wyłącz");
    stop->setEnabled(false);
}

/*
 *  obsługa sygnału wydawanego przez zegar
 */
void MainWindow::zegarek()
{
    czas();
    int m = getMin();
    int s = getSek();
    zegarWyswietlacz->setText("Czas gry:  "+QString::number(m/10)
                               +QString::number(m%10)+":"
                               +QString::number(s/10)+QString::number(s%10));
}
/*
 *  obsługa nowej gry
 */
void MainWindow::nowaGra_clicked()
{
    zegarWyswietlacz->show();
    nowaGra();
    zegarWyswietlacz->setText("Czas gry:  "+QString::number(0)
                              +QString::number(0)+":"
                              +QString::number(0)+QString::number(0));
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
    if(getKlasyczneOpen()||getSamurajOpen())
    {
        int w = sprawdz();
        if(w<0)
        {
            wynikGry->setText("Może innym razem :(");
        }
        else
        {
            if(w>0)
            {
                wynikGry->setText("Gratulacje!!! ;)");
            }
            else
            {
                wynikGry->setText("Są jeszcze puste pola!");
                czekaj->start(2000);
            }
        }
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
    wylacz();
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

void MainWindow::czysc_wynik()
{
    wynikGry->setText("");
    czekaj->stop();
}

void MainWindow::wlacz()
{
    url.setUrl("http://www.rmfon.pl/play,6");
    webview->setUrl(url);
    webview->setGeometry(250,100,850,600);
    webview->show();
    play->setEnabled(false);
    stop->setEnabled(true);
    this->activateWindow();
    czekanie->start(30000);
//    webview->setVisible(false);

}

void MainWindow::wylacz()
{
    url.setUrl("");
    webview->setUrl(url);
    webview->close();
    play->setEnabled(true);
    stop->setEnabled(false);
}

void MainWindow::poczekaniu()
{
    webview->hide();
    czekanie->stop();
}
