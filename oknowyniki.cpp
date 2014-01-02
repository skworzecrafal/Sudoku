#include "oknowyniki.h"

OknoWyniki::OknoWyniki():QMainWindow()
{
    int i,j,k;
    oknoWyniki = new QTabWidget(this);
    oknoWyniki->setWindowTitle("Tablica wyników");
    oknoWyniki->setFixedSize(250,260);
    setFixedSize(250,260);
    oknoWyniki->addTab(poziom[0] = new QWidget(),"Łatwy");
    oknoWyniki->addTab(poziom[1] = new QWidget(),"Średni");
    oknoWyniki->addTab(poziom[2] = new QWidget(),"Trudny");
    oknoWyniki->addTab(poziom[3] = new QWidget(),"Samurajskie");

    for(i=0;i<4;i++)
    {
        for(j=0;j<2;j++)
        {
            info[i][j] = new QLabel(poziom[i]);
        }
        for(j=0;j<10;j++)
            for(k=0;k<3;k++)
            {
                label[i][j][k] = new QLabel(poziom[i]);
            }
    }
}

void OknoWyniki::wypisz(ListaWynikow lista[])
{
    Wynik* indeks;
    int j,min,sek;
    for(int i=0;i<4;i++)
    {
        j = 0;
        if(!lista[i].liczba)
        {
            info[i][0]->setAlignment(Qt::AlignCenter);
            setStyl("MS Shell",QPalette::Text,Qt::black,36);
            info[i][0]->setPalette(paleta);
            info[i][0]->setFont(czcionka);
            info[i][0]->setText("Brak");
            info[i][0]->setGeometry(50,50,150,50);
            liczba[i] = 0;
        }
        else
        {
            info[i][0]->setAlignment(Qt::AlignCenter);
            info[i][1]->setAlignment(Qt::AlignCenter);
            setStyl("MS Shell",QPalette::Text,Qt::black,20);
            info[i][0]->setPalette(paleta);
            info[i][0]->setFont(czcionka);
            info[i][1]->setPalette(paleta);
            info[i][1]->setFont(czcionka);
            info[i][0]->setText("Gracz");
            info[i][1]->setText("Czas");
            info[i][0]->setGeometry(45,5,100,20);
            info[i][1]->setGeometry(145,5,60,20);
            indeks = lista[i].pierwszy;
            do
            {
                for(int k=0;k<3;k++)
                {
                    label[i][j][k]->setAlignment(Qt::AlignCenter);
                }
                label[i][j][0]->setGeometry(30,30+(j*20),15,20);
                label[i][j][1]->setGeometry(45,30+(j*20),100,20);
                label[i][j][2]->setGeometry(145,30+(j*20),60,20);
                min = indeks->getMinuty();
                sek = indeks->getSekundy();
                label[i][j][0]->setText(QString::number(j+1)+".");
                label[i][j][1]->setText(indeks->getImie());
                label[i][j][2]->setText(QString::number(min/10)+QString::number(min%10)+":"+QString::number(sek/10)+QString::number(sek%10));
                j++;
                indeks = indeks->nastepny;
            }while((indeks!=NULL)&&(j!=10));
            liczba[i] = j;
        }
    }
}

void OknoWyniki::zamknij()
{
    int i,j,k;
    for(i=0;i<4;i++)
    {
        for(j=0;j<2;j++)
        {
            info[i][j]->setText("");
        }
        for(j=0;j<10;j++)
            for(k=0;k<3;k++)
            {
                label[i][j][k]->setText("");
            }
    }
}

OknoWyniki::~OknoWyniki()
{
    int i,j,k;
    for(i=0;i<4;i++)
    {
        for(j=0;j<2;j++)
        {
            delete info[i][j];
        }
        for(j=0;j<10;j++)
            for(k=0;k<3;k++)
            {
                delete label[i][j][k];
            }
    }
    for(i=0;i<4;i++)
        delete poziom[i];
    delete oknoWyniki;
}
