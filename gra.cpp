#include "gra.h"

Gra::Gra()
{
    /*
     * ustawienie wartości startowych
     */
    sek = 0;
    min = 0;
    wpisane = 0;
    opcjeOpen = false;
    wynikiOpen = false;
    isClickedCheck = false;
    klasyczneOpen = false;
    samurajOpen = false;

    /*
     *załadowanie listy wyników
     */
    lista[0].wczytaj("wyniki99easy.txt");
    lista[1].wczytaj("wyniki99medium.txt");
    lista[2].wczytaj("wyniki99hard.txt");
    lista[3].wczytaj("wynikisamuraj.txt");

}

void Gra::wywolajKonstruktory(QWidget *parent)
{
    /*
     * utworzenie zagara do gry
     **/
    zegar = new QTimer(parent);
    zegar->stop();

    /*
     * utworzenie obiektow z planszami
     */
    klasyczne = new Plansza99(parent);
    samuraj = new PlanszaSamuraj(parent);
//    samuraj->show();
//    klasyczne->show();
    if(o_opcje.typ == 1)
    {
        o_opcje.easy->setEnabled(true);
        o_opcje.medium->setEnabled(true);
        o_opcje.hard->setEnabled(true);
        o_opcje.etykietaTyp->setText("Wybierz typ gry: \t Klasyczne");
        if(o_opcje.poziomC == 1)
            o_opcje.poziom->setText("Łatwy");
        if(o_opcje.poziomC == 2)
            o_opcje.poziom->setText("Średni");
        if(o_opcje.poziomC == 3)
            o_opcje.poziom->setText("Trudny");
    }
    if(o_opcje.typ == 2)
    {
        o_opcje.easy->setEnabled(false);
        o_opcje.medium->setEnabled(false);
        o_opcje.hard->setEnabled(false);
        o_opcje.etykietaTyp->setText("Wybierz typ gry: \t Samurajskie");
    }

}

/*
 *wypisuje wartości początkowe do planszy klasycznej
 */
void Gra::wypisz(bool w)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(*klasyczne->plansza[i][j].wartoscGra)
            {
                klasyczne->plansza[i][j].format(!w,48);
                klasyczne->plansza[i][j].pole->setText(QString::number(*klasyczne->plansza[i][j].wartoscGra));
            }
            else
            {
                klasyczne->plansza[i][j].format(w,48);
                klasyczne->plansza[i][j].pole->setText("");
            }
        }
    }
}
/*
 * wypisuje wartości początkowe do planszy samurajskiej
 */
void Gra::wypisz(bool w,Komorkas plansza[5][9][9])
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(*plansza[k][i][j].wartoscGra)
                {
                    plansza[k][i][j].format(!w,24);
                    plansza[k][i][j].pole->setText(QString::number(*plansza[k][i][j].wartoscGra));
                }
                else
                {
                    plansza[k][i][j].format(w,24);
                    plansza[k][i][j].pole->setText("");
                }
            }
        }
    }
}

void Gra::nowaGra()
{
    if(klasyczneOpen)
    {
        klasyczne->close();
        klasyczneOpen = false;
    }
    if(samurajOpen)
    {
        samuraj->close();
        samurajOpen = false;
    }
    if(opcjeOpen)
    {
        o_opcje.close();
        opcjeOpen = false;
    }
    if(wynikiOpen)
    {
        o_wyniki.zamknij();
        o_wyniki.close();
        wynikiOpen = false;
    }
    if(o_opcje.typ == 1)
    {
        klasyczne->show();
        klasyczneOpen = true;
    }
    if(o_opcje.typ == 2)
    {
        samuraj->show();
        samurajOpen = true;
    }
    wpisane = 0;
    min=sek=0;

    zegar->start(1000);
    generuj(o_opcje.typ);
    isClickedCheck = false;
}

void Gra::opcje()
{
    o_opcje.show();
    opcjeOpen = true;
}

void Gra::wyniki()
{
    if(wynikiOpen)
        o_wyniki.zamknij();
    o_wyniki.oknoWyniki->setCurrentIndex(0);
    o_wyniki.wypisz(lista);
    o_wyniki.show();
    wynikiOpen = true;
}

void Gra::wyjscie()
{
    lista[0].zapisz("wyniki99easy.txt");
    lista[1].zapisz("wyniki99medium.txt");
    lista[2].zapisz("wyniki99hard.txt");
    lista[3].zapisz("wynikisamuraj.txt");
    zapiszConf();
    if(klasyczneOpen)
        klasyczne->close();
    if(samurajOpen)
        samuraj->close();
    if(opcjeOpen)
    {
        o_opcje.close();
    }
    if(wynikiOpen)
    {
        o_wyniki.zamknij();
        o_wyniki.close();
    }
}

int Gra::sprawdz(Komorka plansza[9][9])
{
    bool war=true;
    wpisane = 0;
    int w,k,su,sum[9]={0,0,0,0,0,0,0,0,0};
    for(w=0;w<9;w++)
        for(k=0;k<9;k++)
            if(*plansza[w][k].wartoscGra)
                wpisane++;
    if(wpisane==81)
    {
        zegar->stop();
        for (w=0;w<9;w++)
        {
            su=0;
            for (k=0;k<9;k++)
            {
                su+=*plansza[w][k].wartoscGra;
                sum[k]+=*plansza[w][k].wartoscGra;
            }
            if(su!=45)
            {
                war=false;
                break;
            }
        }
        for (w=0;w<9;w++)
            if(sum[w]!=45)
            {
                war=false;
                break;
            }
        if (war)
        {
            if(!isClickedCheck)
            {

                o_dodajWynik.show();
                o_dodajWynik.gracz->setFocus();
                o_dodajWynik.gracz->selectAll();
            }
            isClickedCheck = true;
            return 1;

        }
        else
        {
            isClickedCheck = true;
            return -1;
        }
    }
    return 0;
}

int Gra::sprawdz(Komorkas plansza[5][9][9])
{
    bool war=true;
    wpisane = 0;
    int w,k,n,su,sum[9]={0,0,0,0,0,0,0,0,0};
    for(n=0;n<5;n++)
        for(w=0;w<9;w++)
            for(k=0;k<9;k++)
                if(*plansza[n][w][k].wartoscGra)
                    wpisane++;
    if(wpisane == 405)
    {
        zegar->stop();
        for(n=0;n<5;n++)
        {
            for(w=0;w<9;w++)
                sum[w]=0;
            for (w=0;w<9;w++)
            {
                su=0;
                for (k=0;k<9;k++)
                {
                    su+=*plansza[n][w][k].wartoscGra;
                    sum[k]+=*plansza[n][w][k].wartoscGra;
                }
                if(su!=45)
                {
                    war=false;
                    break;
                }
            }
            for (w=0;w<9;w++)
                if(sum[w]!=45)
                {
                    war=false;
                    break;
                }
            if(!war)
            {
                break;
            }
        }
        if (war)
        {
            if(!isClickedCheck)
            {

                o_dodajWynik.show();
                o_dodajWynik.gracz->setFocus();
                o_dodajWynik.gracz->selectAll();
            }
            isClickedCheck = true;
            return 1;

        }
        else
        {
            isClickedCheck = true;
            return -1;
        }
    }
    return 0;
}

int Gra::sprawdz()
{
    if(o_opcje.typ == 1)
    {
        return sprawdz(klasyczne->plansza);
    }
    if(o_opcje.typ == 2)
    {
        return sprawdz(samuraj->tab);
    }
    return 0;
}

void Gra::czas()
{
    sek++;
    if(sek>59)
    {
        min++;
        sek = 0;
    }
}

void Gra::dodWynik()
{
    if(o_opcje.typ == 1)
        o_dodajWynik.dodaj(lista,o_opcje.poziomC,min,sek);
    if(o_opcje.typ == 2)
        o_dodajWynik.dodaj(lista,4,min,sek);
    o_dodajWynik.close();
}

void Gra::wczytajConf()
{
    std::fstream dane;
    dane.open("conf.txt",std::ios::in);
    if(dane.is_open())
    {
        dane>>o_opcje.poziomC>>o_opcje.typ;
        dane.close();
    }
}

void Gra::zapiszConf()
{
    std::fstream plik;
    plik.open("conf.txt",std::ios::out | std::ios::trunc);
    plik<<o_opcje.poziomC<<" "<<o_opcje.typ;
    plik.close();
}

void Gra::generuj(int typ)
{
    int i,j;
    if(typ==1)
    {
        generowanie(klasyczne->plansza,o_opcje.poziomC);
        wypisz(true);
    }
    if(typ==2)
    {
        samuraj->zerujPola();
        generowanie(samuraj->tab,4);
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
                *samuraj->tab[4][i][j].backupWart = *samuraj->tab[4][i][j].wartoscZnana;
        for(int nr=0;nr<4;nr++)
        {
        generowanie(samuraj->tab,nr);
        }
        wypisz(true,samuraj->tab);
    }
}
