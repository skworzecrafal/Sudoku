#include "plansza99.h"

Plansza99::Plansza99(QWidget *parent):QWidget(parent)
{
    int i,j;
    close();
    setGeometry(30,60,600,660);
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            plansza[i][j].pole->setParent(this);
            plansza[i][j].pole->setGeometry(j*60+30,i*60+65,60,60);
        }
    for (int w=0;w<4;w++)
    {
        if ((w==0)||(w==3))
        {
            linie[w] = new QFrame(this);
            linie[w]->setGeometry((w)*180+28,65,5,540);
            linie[w]->setFrameShape(QFrame::VLine);
            linie[w]->setFrameShadow(QFrame::Plain);
            linie[w]->setLineWidth(5);
        }
        else
        {
            linie[w] = new QFrame(this);
            linie[w]->setGeometry((w)*180+28,65,5,540);
            linie[w]->setFrameShape(QFrame::VLine);
            linie[w]->setFrameShadow(QFrame::Plain);
            linie[w]->setLineWidth(3);
        }
    }
    for (int w=4;w<8;w++)
    {
        if ((w==4)||(w==7))
        {
            linie[w] = new QFrame(this);
            linie[w]->setGeometry(28,(w-4)*180+63,545,5);
            linie[w]->setFrameShape(QFrame::HLine);
            linie[w]->setFrameShadow(QFrame::Plain);
            linie[w]->setLineWidth(5);
        }
        else
        {
            linie[w] = new QFrame(this);
            linie[w]->setGeometry(28,(w-4)*180+63,545,5);
            linie[w]->setFrameShape(QFrame::HLine);
            linie[w]->setFrameShadow(QFrame::Plain);
            linie[w]->setLineWidth(3);
        }
    }
}

Plansza99::~Plansza99()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        delete linie[i];
    }
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            delete plansza[i][j].wartoscGra;
            delete plansza[i][j].wartoscZnana;
        }
}
