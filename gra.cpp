#include "gra.h"

Gra::Gra(QWidget *parent)
{
    instrukcja = new QLabel();
    instrukcja->close();
    setStyl("Comic Sans MS",QPalette::Text,Qt::black,15);
    instrukcja->setPalette(paleta);
    instrukcja->setFont(czcionka);
    instrukcja->setText("   + W Sudoku klasycznym trzeba wypełnić planszę tak,\n"
                        "   aby w każdym wierszu oraz w każdej kolumnie\n"
                        "   i w każdym małym kwadracie 3x3 znalazły się\n"
                        "   cyfry od 1 do 9, gdzie cyfry te nie mogą się\n"
                        "   powtarzać w żadnym wierszu, kolumnie i małym\n"
                        "   kwadracie 3x3.\n"
                        "   \n"
                        "   + W Sudoku samurajskim obowiązują te same zasady\n"
                        "   co w Sudoku Klasycznym, dla każdej z pięciu planszy\n"
                        "   o wymiarach 9x9. Dodatkowo są cztery kwadraty 3x3,\n"
                        "   które są częścią wspólna dwóch z pięciu plansz 9x9.\n"
                        "   \n"
                        "   + Typ i poziom trudności można wybrać w menu opcje.\n"
                        "   \n"
                        "   + W trakcie gry aby wstawić cyfrę do planszy klinknij\n"
                        "   odpowiednie pole a następnie wpisz cyfrę używając\n"
                        "   klawiatury. Po wypełnieniu wszystkich pól kliknij\n"
                        "   klawisz \"Sprawdź rozwiązanie\" w celu sprawdzenia\n"
                        "   poprawności wypełnienia planszy.\n"
                        "   \n"
                        "   + W trakcie rozwiązywania można skorzystać\n"
                        "   z podpowiedzi. Ich liczba jest ograniczona zależnie\n"
                        "   od wybranego typu gry i poziomu trudności.");
    instrukcja->setFixedSize(400,490);

    inf_lpodp = new QLabel(parent);
    inf_lpodp->setGeometry(770,635,230,20);
    setStyl("Comic Sans MS",QPalette::Text,Qt::black,19);
    inf_lpodp->setPalette(paleta);
    inf_lpodp->setFont(czcionka);
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
    pomocOpen = false;

    /*
     *załadowanie listy wyników
     */
    lista[0].wczytaj("wyniki99easy.sud");
    lista[1].wczytaj("wyniki99medium.sud");
    lista[2].wczytaj("wyniki99hard.sud");
    lista[3].wczytaj("wynikisamuraj.sud");

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

}

Gra::~Gra()
{
    delete zegar;
    delete klasyczne;
    delete samuraj;
    delete instrukcja;
    delete inf_lpodp;
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
    if(pomocOpen)
    {
        instrukcja->close();
        pomocOpen = true;
    }
    if(o_opcje.typ == 1)
    {
        klasyczne->show();
        klasyczneOpen = true;
        if(o_opcje.poziomC==1)
        {
            lPodpowiedzi = 3;
            inf_lpodp->setText("Pozostało "+QString::number(lPodpowiedzi)+" podpowiedzi.");
        }
        if(o_opcje.poziomC==2)
        {
            lPodpowiedzi = 4;
            inf_lpodp->setText("Pozostało "+QString::number(lPodpowiedzi)+" podpowiedzi.");
        }
        if(o_opcje.poziomC==3)
        {
            lPodpowiedzi = 5;
            inf_lpodp->setText("Pozostało "+QString::number(lPodpowiedzi)+" podpowiedzi.");
        }
    }
    if(o_opcje.typ == 2)
    {
        samuraj->show();
        samurajOpen = true;
        lPodpowiedzi = 5;
        inf_lpodp->setText("Pozostało "+QString::number(lPodpowiedzi)+" podpowiedzi.");
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
    lista[0].zapisz("wyniki99easy.sud");
    lista[1].zapisz("wyniki99medium.sud");
    lista[2].zapisz("wyniki99hard.sud");
    lista[3].zapisz("wynikisamuraj.sud");
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

void Gra::zapiszConf()
{
    std::fstream plik;
    plik.open("conf.sud",std::ios::out | std::ios::trunc);
    plik<<o_opcje.poziomC<<" "<<o_opcje.typ;
    plik.close();
}

void Gra::resetWynikow()
{
    for(int i=0;i<4;i++)
        lista[i].listaCzysc();
}

void Gra::podpowiedz(Komorka plansza[9][9])
{
    int tab1[81];
    int w,k,wsp,rozm=0;
    srand(time(NULL));
    for(w=0;w<9;w++)
        for(k=0;k<9;k++)
        {
            if(!*plansza[w][k].wartoscGra)
            {
                tab1[rozm]=w*10+k;
                rozm++;
            }
        }
    if(rozm)
    {
        wsp = rand() % rozm;
        w = tab1[wsp]/10;
        k = tab1[wsp] % 10;
        plansza[w][k].pole->setText(QString::number(*plansza[w][k].wartoscZnana));
        plansza[w][k].pole->editingFinished();
    }
}

void Gra::podpowiedz(Komorkas plansza[5][9][9])
{
    int tab1[5][81];
    int w,k,nr,wsp,rozm[5],log[5],ktore=0,i;
    srand(time(NULL));
    for(nr=0;nr<5;nr++)
    {
        rozm[nr] = 0;
        for(w=0;w<9;w++)
            for(k=0;k<9;k++)
            {
                if(!*plansza[nr][w][k].wartoscGra)
                {
                    tab1[nr][rozm[nr]]=w*10+k;
                    rozm[nr]+=1;
                }
            }
        if(rozm[nr])
        {
            log[ktore] = nr;
            ktore++;
        }
    }
    if(ktore)
    {
        i = rand() % ktore;
        nr = log[i];
        i = rozm[nr];
        wsp = rand() % i;
        w = tab1[nr][wsp]/10;
        k = tab1[nr][wsp] % 10;
        plansza[nr][w][k].pole->setText(QString::number(*plansza[nr][w][k].wartoscZnana));
        plansza[nr][w][k].pole->editingFinished();
    }
}

int Gra::podpowiedz()
{
    if(lPodpowiedzi)
    {
        if(o_opcje.typ == 1)
            podpowiedz(klasyczne->plansza);
        if(o_opcje.typ == 2)
            podpowiedz(samuraj->tab);
        lPodpowiedzi--;
        if(lPodpowiedzi==1)
        {
                inf_lpodp->setText("Pozostała "+QString::number(lPodpowiedzi)+" podpowiedź.");
        }
        else
        {
            inf_lpodp->setText("Pozostało "+QString::number(lPodpowiedzi)+" podpowiedzi.");\
        }
    }
    return lPodpowiedzi;
}

void Gra::pomoc()
{
    instrukcja->show();
    pomocOpen = true;
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
