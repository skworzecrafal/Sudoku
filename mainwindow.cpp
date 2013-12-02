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
    connect(oknoOpcje.easy,SIGNAL(clicked()),this,SLOT(on_easy_clicked()));
    connect(oknoOpcje.medium,SIGNAL(clicked()),this,SLOT(on_medium_clicked()));
    connect(oknoOpcje.hard,SIGNAL(clicked()),this,SLOT(on_hard_clicked()));
    connect(oknoOpcje.reset,SIGNAL(clicked()),this,SLOT(resetWynikow()));
    connect(dodajWynik.ok,SIGNAL(clicked()),this,SLOT(nowyWynik()));
    connect(dodajWynik.gracz,SIGNAL(returnPressed()),this,SLOT(nowyWynik()));
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
        close99();
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

    show99();
    wpisane = 0;
    ui->Koniec->setText("");
    min=sek=0;
    ui->czas->setText(QString::number(min/10)+QString::number(min%10)+":"+QString::number(sek/10)+QString::number(sek%10));

    zegar->start(1000);
    g.generowanie(plansza,oknoOpcje.poziomC);
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
            if(plansza[i][j].wartoscGra)
            {
                plansza[i][j].format(!w);
                plansza[i][j].pole->setText(QString::number(plansza[i][j].wartoscGra));
            }
            else
            {
                plansza[i][j].format(w);
                plansza[i][j].pole->setText("");
            }
        }
    }
}
/*
 *wyświetlenie planszy o wymiarach 9x9
 */
void MainWindow::show99()
{
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            plansza[i][j].pole->setParent(this);
            plansza[i][j].pole->setGeometry(j*60+60,i*60+125,60,60);
            plansza[i][j].pole->show();
        }
    for (int w=0;w<4;w++)
    {
        if ((w % 3==0)&&((w==0)||(w==3)))
        {
            linie[w] = new QFrame(this);
            linie[w]->setGeometry((w)*180+58,125,5,540);
            linie[w]->setFrameShape(QFrame::VLine);
            linie[w]->setFrameShadow(QFrame::Plain);
            linie[w]->setLineWidth(5);
            linie[w]->show();
        }
        else
        {
            linie[w] = new QFrame(this);
            linie[w]->setGeometry((w)*180+58,125,5,540);
            linie[w]->setFrameShape(QFrame::VLine);
            linie[w]->setFrameShadow(QFrame::Plain);
            linie[w]->setLineWidth(3);
            linie[w]->show();
        }
    }
    for (int w=4;w<8;w++)
    {
        if ((w % 3==1)&&((w==4)||(w==7)))
        {
            linie[w] = new QFrame(this);
            linie[w]->setGeometry(58,(w-4)*180+123,545,5);
            linie[w]->setFrameShape(QFrame::HLine);
            linie[w]->setFrameShadow(QFrame::Plain);
            linie[w]->setLineWidth(5);
            linie[w]->show();
        }
        else
        {
            linie[w] = new QFrame(this);
            linie[w]->setGeometry(58,(w-4)*180+123,545,5);
            linie[w]->setFrameShape(QFrame::HLine);
            linie[w]->setFrameShadow(QFrame::Plain);
            linie[w]->setLineWidth(3);
            linie[w]->show();
        }
    }
}
/*
 *wyłącza plansze 9x9
 */
void MainWindow::close99()
{
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            plansza[i][j].pole->close();
        }
    for(i=0;i<8;i++)
    {
        linie[i]->close();
        delete linie[i];
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
            if(plansza[w][k].wartoscGra)
                wpisane++;
    if(wpisane==81)
    {
        zegar->stop();
        for (int w=0;w<9;w++)
        {
            su=0;
            for (int k=0;k<9;k++)
            {
                su+=plansza[w][k].wartoscGra;
                sum[k]+=plansza[w][k].wartoscGra;
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
            if(!plansza[w][k].wartoscGra)
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
        plansza[w][k].pole->setText(QString::number(plansza[w][k].wartoscZnana));
        plansza[w][k].pole->editingFinished();
    }
}

void MainWindow::on_pomoc_2_clicked()
{

    for(int w=0;w<9;w++)
        for(int k=0;k<9;k++)
        {
            plansza[w][k].pole->setText(QString::number(plansza[w][k].wartoscZnana));
            plansza[w][k].pole->editingFinished();
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
        close99();
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
void MainWindow::on_easy_clicked()
{
    min = sek = 0;
    zegar->stop();
    if(isClickedNG)
    {
        close99();
        isClickedNG = false;
    }
}
/*
 *poziom średni
 */
void MainWindow::on_medium_clicked()
{
    min = sek = 0;
    zegar->stop();
    if(isClickedNG)
    {
        close99();
        isClickedNG = false;
    }
}
/*
 *poziom trudny
 */
void MainWindow::on_hard_clicked()
{
    min = sek = 0;
    zegar->stop();
    if(isClickedNG)
    {
        close99();
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
