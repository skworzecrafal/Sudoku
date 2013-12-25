#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
     * ustawienie wartości startowych
     */
    sek = 0;
    min = 0;
    isClickedNG = false;
    isClickedOpcje = false;
    isClickedTW = false;
    isClickedCheck = false;
    /*
     * utworzenie zagara do gry
     **/
    zegar = new QTimer(this);
    zegar->stop();
    connect(zegar,SIGNAL(timeout()),SLOT(zegarek()));
    /*
     *załadowanie listy wyników
     */
    lista[0].wczytaj("wyniki99easy.txt");
    lista[1].wczytaj("wyniki99medium.txt");
    lista[2].wczytaj("wyniki99hard.txt");
    /*
     *ustawienie akcji do buttonów
     */
    connect(oknoOpcje.easy,SIGNAL(clicked()),SLOT(easy_clicked()));
    connect(oknoOpcje.medium,SIGNAL(clicked()),this,SLOT(medium_clicked()));
    connect(oknoOpcje.hard,SIGNAL(clicked()),this,SLOT(hard_clicked()));
    connect(oknoOpcje.reset,SIGNAL(clicked()),this,SLOT(resetWynikow()));
    connect(dodajWynik.ok,SIGNAL(clicked()),this,SLOT(nowyWynik()));
    connect(dodajWynik.gracz,SIGNAL(returnPressed()),this,SLOT(nowyWynik()));

    plansza99 = new Plansza99(this);
}

MainWindow::~MainWindow()
{
    delete zegar;
    delete ui;
}

/*
 *  obsługa sygnału wydawanego przez zegar
 */
void MainWindow::zegarek()
{
     sek++;
     if(sek>59)
     {
         min++;
         sek = 0;
     }
     ui->czas->setText(QString::number(min/10)+QString::number(min%10)+":"+QString::number(sek/10)+QString::number(sek%10));
}
/*
 *  obsługa nowej gry
 */
void MainWindow::on_nowaGra_clicked()
{
    if(isClickedNG)
        plansza99->close();
    if(isClickedOpcje)
    {
        oknoOpcje.oknoOpcje->close();
        isClickedOpcje = false;
    }
    if(isClickedTW)
    {
        okno.zamknij();
        okno.oknoWyniki->close();
        isClickedTW = false;
    }

    plansza99->show();
    wpisane = 0;
    ui->Koniec->setText("");
    min=sek=0;
    ui->czas->setText(QString::number(min/10)+QString::number(min%10)+":"+QString::number(sek/10)+QString::number(sek%10));

    zegar->start(1000);
    g.generowanie(plansza99->plansza,oknoOpcje.poziomC);
    wypisz(true);
    isClickedNG = true;
    isClickedCheck = false;
}
/*
 *wypisuje wartości początkowe do planszy
 */
void MainWindow::wypisz(bool w)
{
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(plansza99->plansza[i][j].wartoscGra)
            {
                plansza99->plansza[i][j].format(!w);
                plansza99->plansza[i][j].pole->setText(QString::number(plansza99->plansza[i][j].wartoscGra));
            }
            else
            {
                plansza99->plansza[i][j].format(w);
                plansza99->plansza[i][j].pole->setText("");
            }
        }
    }
}
/*
 *otwiera okno opcji
 */

void MainWindow::on_opcje_clicked()
{
    oknoOpcje.oknoOpcje->show();
    isClickedOpcje = true;
}
/*
 *sprawdza rozwiązanie
 */
void MainWindow::on_Check_clicked()
{

    bool war=true;
    wpisane = 0;
    int su,sum[9]={0,0,0,0,0,0,0,0,0};
    for(int w=0;w<9;w++)
        for(int k=0;k<9;k++)
            if(plansza99->plansza[w][k].wartoscGra)
                wpisane++;
    if(wpisane==81)
    {
        zegar->stop();
        for (int w=0;w<9;w++)
        {
            su=0;
            for (int k=0;k<9;k++)
            {
                su+=plansza99->plansza[w][k].wartoscGra;
                sum[k]+=plansza99->plansza[w][k].wartoscGra;
            }
            if(su!=45)
            {
                war=false;
                break;
            }
        }
        for (int w=0;w<9;w++)
            if(sum[w]!=45)
            {
                war=false;
                break;
            }
        if (war)
        {
            ui->Koniec->setText("Brawo!!! :D");
            if(!isClickedCheck)
            {

                dodajWynik.okno->show();
                dodajWynik.gracz->setFocus();
                dodajWynik.gracz->selectAll();
            }
            isClickedCheck = true;

        }
        else
            ui->Koniec->setText("Może innym razem ;)");
    }
}

void MainWindow::on_pomoc_clicked()
{
    int tabl[9][9],tab1[81];
    int w,k,wsp,rozm=0;
    srand(time(NULL));
    for(w=0;w<9;w++)
        for(k=0;k<9;k++)
        {
            tabl[w][k]=w*10+k;

        }
    for(w=0;w<9;w++)
        for(k=0;k<9;k++)
        {
            if(!plansza99->plansza[w][k].wartoscGra)
            {
                tab1[rozm]=tabl[w][k];
                rozm++;
            }

        }
    if(rozm)
    {
        wsp = rand() % rozm;
        w = tab1[wsp]/10;
        k = tab1[wsp] % 10;
        plansza99->plansza[w][k].pole->setText(QString::number(plansza99->plansza[w][k].wartoscZnana));
        plansza99->plansza[w][k].pole->editingFinished();
    }
}

void MainWindow::on_pomoc_2_clicked()
{

    for(int w=0;w<9;w++)
        for(int k=0;k<9;k++)
        {
            plansza99->plansza[w][k].pole->setText(QString::number(plansza99->plansza[w][k].wartoscZnana));
            plansza99->plansza[w][k].pole->editingFinished();
        }
}
/*
 *wyjście z programu i zapisanie listy wyników do plików
 */
void MainWindow::on_wyjscie_clicked()
{
    lista[0].zapisz("wyniki99easy.txt");
    lista[1].zapisz("wyniki99medium.txt");
    lista[2].zapisz("wyniki99hard.txt");
    if(isClickedNG)
        plansza99->close();
    if(isClickedOpcje)
    {
        oknoOpcje.oknoOpcje->close();
    }
    if(isClickedTW)
    {
        okno.zamknij();
        okno.oknoWyniki->close();
    }
}
/*
 * poziom łatwy
 */
void MainWindow::easy_clicked()
{
    min = sek = 0;
    zegar->stop();
    if(isClickedNG)
    {
        plansza99->close();
        isClickedNG = false;
    }
}
/*
 *poziom średni
 */
void MainWindow::medium_clicked()
{
    min = sek = 0;
    zegar->stop();
    if(isClickedNG)
    {
        plansza99->close();
        isClickedNG = false;
    }
}
/*
 *poziom trudny
 */
void MainWindow::hard_clicked()
{
    min = sek = 0;
    zegar->stop();
    if(isClickedNG)
    {
        plansza99->close();
        isClickedNG = false;
    }
}
/*
 *otwarcie okna z listą wyników
 */
void MainWindow::on_tabWyn_clicked()
{
    if(isClickedTW)
        okno.zamknij();
    okno.oknoWyniki->setCurrentIndex(0);
    okno.wypisz(lista);
    okno.oknoWyniki->show();
    isClickedTW = true;
}
/*
 *reset listy wyników
 */
void MainWindow::resetWynikow()
{
    for(int i=0;i<3;i++)
        lista[i].~ListaWynikow();
}
/*
 *slot dodania nowego wyniku
 */
void MainWindow::nowyWynik()
{
    dodajWynik.dodaj(lista,oknoOpcje.poziomC,min,sek);
    dodajWynik.okno->close();
}
