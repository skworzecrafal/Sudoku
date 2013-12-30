#include "planszasamuraj.h"

PlanszaSamuraj::PlanszaSamuraj(QWidget *parent):QWidget(parent)
{
    int i,j;
    setGeometry(30,70,660,650);
    close();
    for( i=0;i<9;i++)
        for( j=0;j<9;j++)
        {
            tab[0][i][j].pole->setParent(this);
            tab[0][i][j].pole->setGeometry(j*30+15,i*30+10,30,30);
            tab[1][i][j].pole->setParent(this);
            tab[1][i][j].pole->setGeometry(j*30+375,i*30+10,30,30);
            tab[2][i][j].pole->setParent(this);
            tab[2][i][j].pole->setGeometry(j*30+15,i*30+370,30,30);
            tab[3][i][j].pole->setParent(this);
            tab[3][i][j].pole->setGeometry(j*30+375,i*30+370,30,30);
        }
    for( i=0;i<9;i++)
        for( j=0;j<9;j++)
        {
            if((i<3)&&(j<3))
            {
                tab[4][i][j]=tab[0][i+6][j+6];
            }
            else if((i<3)&&(j>5))
            {
                tab[4][i][j]=tab[1][i+6][j-6];
            }
            else if((i>5)&&(j<3))
            {
                tab[4][i][j]=tab[2][i-6][j+6];
            }
            else if((i>5)&&(j>5))
            {
                tab[4][i][j]= tab[3][i-6][j-6];
            }
            else
            {
                tab[4][i][j].pole->setParent(this);
                tab[4][i][j].pole->setGeometry(j*30+195,i*30+190,30,30);
            }
        }
    int x,yv,yh,modul;
    for(int i=0;i<20;i++)
    {
        switch (i/4) {
        case 0:
            x = 13;
            yv = 10;
            yh = 8;
            break;
        case 1:
            x = 373;
            yv = 10;
            yh = 8;
            break;
        case 2:
            x = 13;
            yv = 370;
            yh = 368;
            break;
        case 3:
            x = 373;
            yv = 370;
            yh = 368;
            break;
        case 4:
            x = 193;
            yv = 190;
            yh = 188;
            break;
        default:
            break;
        }
        if(i%4==0)
            modul = i % 3;
        if (i%3==modul)
        {
            linie[i] = new QFrame(this);
            linie[i]->setGeometry((i-i/4*4)*90+x,yv,5,270);
            linie[i]->setFrameShape(QFrame::VLine);
            linie[i]->setFrameShadow(QFrame::Plain);
            linie[i]->setLineWidth(3);
            linie[i+20] = new QFrame(this);
            linie[i+20]->setGeometry(x+1,(i-i/4*4)*90+yh,273,5);
            linie[i+20]->setFrameShape(QFrame::HLine);
            linie[i+20]->setFrameShadow(QFrame::Plain);
            linie[i+20]->setLineWidth(3);
        }
        else
        {
            linie[i] = new QFrame(this);
            linie[i]->setGeometry((i-i/4*4)*90+x,yv,5,270);
            linie[i]->setFrameShape(QFrame::VLine);
            linie[i]->setFrameShadow(QFrame::Plain);
            linie[i]->setLineWidth(2);
            linie[i+20] = new QFrame(this);
            linie[i+20]->setGeometry(x+1,(i-i/4*4)*90+yh,273,5);
            linie[i+20]->setFrameShape(QFrame::HLine);
            linie[i+20]->setFrameShadow(QFrame::Plain);
            linie[i+20]->setLineWidth(2);
        }
    }
}

void PlanszaSamuraj::zerujPola()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            for(int k=0;k<5;k++)
                tab[k][i][j].zeruj();
}

PlanszaSamuraj::~PlanszaSamuraj()
{
    int i,j,k;
    for( i=0;i<9;i++)
        delete linie[i];
    for( i=0;i<9;i++)
        for( j=0;j<9;j++)
            for(k=0;k<4;k++)
            {
                delete tab[k][i][j].wartoscGra;
                delete tab[k][i][j].backupWart;
                delete tab[k][i][j].wartoscZnana;
            }
    for( i=0;i<9;i++)
        for( j=0;j<9;j++)
        {
            if((i<3)&&(j<3)){continue;}
            if((i<3)&&(j>5)){continue;}
            if((i>5)&&(j<3)){continue;}
            if((i>5)&&(j>5)){continue;}
            {
                delete tab[4][i][j].wartoscGra;
                delete tab[4][i][j].backupWart;
                delete tab[4][i][j].wartoscZnana;
            }
        }
}
