#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sek = 0;
    min = 0;
    isClickedNG = false;
    isClickedOpcje = false;
    isClickedTW = false;
    zegar = new QTimer(this);
    zegar->stop();
    connect(zegar,SIGNAL(timeout()),SLOT(zegarek()));
    lista[0].wczytaj("wyniki99easy.txt");
    lista[1].wczytaj("wyniki99medium.txt");
    lista[2].wczytaj("wyniki99hard.txt");
    connect(oknoOpcje.easy,SIGNAL(clicked()),this,SLOT(on_easy_clicked()));
    connect(oknoOpcje.medium,SIGNAL(clicked()),this,SLOT(on_medium_clicked()));
    connect(oknoOpcje.hard,SIGNAL(clicked()),this,SLOT(on_hard_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

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

void MainWindow::doTablicy99()
{
    wpisane = 0;
    for (int w=0;w<9;w++)
        for (int k=0;k<9;k++)
        {
            tab.tablica[w][k]=plansza[w][k].pole->text().toInt();
            if (!tab.tablica[w][k])
                plansza[w][k].pole->setText("");
            else
                wpisane++;
        }
}

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
    g.generowanie(tab.tablica,tab.tabPelna,oknoOpcje.poziomC);
    wypisz(true);
    isClickedNG=true;
}
void MainWindow::wypisz(bool w)
{
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(tab.tablica[i][j])
            {
                plansza[i][j].format(!w);
                plansza[i][j].pole->setText(QString::number(tab.tablica[i][j]));
            }
            else
            {
                plansza[i][j].format(w);
                plansza[i][j].pole->setText("");
            }
        }
    }
}

void MainWindow::show99()
{
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            plansza[i][j].pole = new QLineEdit(this);
            plansza[i][j].pole->setGeometry(j*60+60,i*60+125,60,60);
            plansza[i][j].pole->show();
            connect(plansza[i][j].pole,SIGNAL(editingFinished()),SLOT(doTablicy99()));
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

void MainWindow::close99()
{
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            plansza[i][j].pole->close();
            delete plansza[i][j].pole;
        }
    for(i=0;i<8;i++)
    {
        linie[i]->close();
        delete linie[i];
    }
    disconnect();
}


void MainWindow::on_opcje_clicked()
{
    oknoOpcje.oknoOpcje->show();
    isClickedOpcje = true;
}

void MainWindow::on_Check_clicked()
{

    bool war=true;
    int su,sum[9]={0,0,0,0,0,0,0,0,0};
    if(wpisane==81)
    {
        zegar->stop();
        for (int w=0;w<9;w++)
        {
            su=0;
            for (int k=0;k<9;k++)
            {
                su+=tab.tablica[w][k];
                sum[k]+=tab.tablica[w][k];
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
        Wynik* wynik;
        if (war)
        {
            ui->Koniec->setText("Brawo!!! :D");
            wynik = new Wynik();
            wynik->setImie("zanek");
            wynik->setMinuty(min);
            wynik->setSekundy(sek);
            lista[oknoOpcje.poziomC - 1].dodaj(wynik);

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
            if(!tab.tablica[w][k])
            {
                tab1[rozm]=tabl[w][k];
                rozm++;
            }

        }
    wsp = rand() % rozm;
    w = tab1[wsp]/10;
    k = tab1[wsp] % 10;
    plansza[w][k].pole->setText(QString::number(tab.tabPelna[w][k]));
}

void MainWindow::on_pomoc_2_clicked()
{

    for(int w=0;w<9;w++)
        for(int k=0;k<9;k++)
        {
            plansza[w][k].pole->setText(QString::number(tab.tabPelna[w][k]));
        }
}

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




void MainWindow::on_tabWyn_clicked()
{
    if(isClickedTW)
        okno.zamknij();
    okno.wypisz(lista);
    okno.oknoWyniki->show();
    isClickedTW = true;
}
