#include "planszasamuraj.h"

PlanszaSamuraj::PlanszaSamuraj(QWidget *parent)
{
    pole = new QWidget(parent);
    pole->setGeometry(30,70,660,650);
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            lg[i][j].pole->setParent(pole);
            lg[i][j].pole->setGeometry(j*30+15,i*30+10,30,30);
            rg[i][j].pole->setParent(pole);
            rg[i][j].pole->setGeometry(j*30+375,i*30+10,30,30);
            ld[i][j].pole->setParent(pole);
            ld[i][j].pole->setGeometry(j*30+15,i*30+370,30,30);
            rd[i][j].pole->setParent(pole);
            rd[i][j].pole->setGeometry(j*30+375,i*30+370,30,30);
        }
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if((i<3)&&(j<3))
            {
                sr[i][j]=lg[i+6][j+6];
            }
            else if((i<3)&&(j>5))
            {
                sr[i][j]=rg[i+6][j-6];
            }
            else if((i>5)&&(j<3))
            {
                sr[i][j]=ld[i-6][j+6];
            }
            else if((i>5)&&(j>5))
            {
                sr[i][j]= rd[i-6][j-6];
            }
            else
            {
                sr[i][j].pole->setParent(pole);
                sr[i][j].pole->setGeometry(j*30+195,i*30+190,30,30);
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
            linie[i] = new QFrame(pole);
            linie[i]->setGeometry((i-i/4*4)*90+x,yv,5,270);
            linie[i]->setFrameShape(QFrame::VLine);
            linie[i]->setFrameShadow(QFrame::Plain);
            linie[i]->setLineWidth(3);
            linie[i+20] = new QFrame(pole);
            linie[i+20]->setGeometry(x+1,(i-i/4*4)*90+yh,273,5);
            linie[i+20]->setFrameShape(QFrame::HLine);
            linie[i+20]->setFrameShadow(QFrame::Plain);
            linie[i+20]->setLineWidth(3);
        }
        else
        {
            linie[i] = new QFrame(pole);
            linie[i]->setGeometry((i-i/4*4)*90+x,yv,5,270);
            linie[i]->setFrameShape(QFrame::VLine);
            linie[i]->setFrameShadow(QFrame::Plain);
            linie[i]->setLineWidth(2);
            linie[i+20] = new QFrame(pole);
            linie[i+20]->setGeometry(x+1,(i-i/4*4)*90+yh,273,5);
            linie[i+20]->setFrameShape(QFrame::HLine);
            linie[i+20]->setFrameShadow(QFrame::Plain);
            linie[i+20]->setLineWidth(2);
        }
    }
}
