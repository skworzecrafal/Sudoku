#include "generacja.h"

Generacja::Generacja()
{
}
void Generacja::wiersz(int w,int** t)
{
    int i;
    for (i=0;i<9;i++)
        t[w][i]=0;
}

void Generacja::kolumna(int k,int** t)
{
    int i;
    for (i=0;i<9;i++)
        t[i][k]=0;
}

void Generacja::kwadrat(int w, int k, int** t)
{
    int i,j;
    for (i=((w/3)*3);i<((w/3)*3)+3;i++)
        for (j=((k/3)*3);j<((k/3)*3)+3;j++)
            t[i][j]=0;
}

void Generacja::generowanie(Komorka plansza[9][9], int ile)
{
    int *tabWsp;
    int **tabLog;
    int **tabKwWsp;
    int rozmiarWsp=0;
    int i,j,w,k,liczZap,cyfra,wsp;
    bool warunek=true;

    srand(time(NULL));

    tabWsp = new int[81];
    tabLog = new int*[9];
    for(i=0;i<9;i++)
        *(tabLog+i) = new int[9];
    tabKwWsp = new int*[9];
    for(i=0;i<9;i++)
        *(tabKwWsp+i) = new int[9];
    while(warunek)
    {
        rozmiarWsp=0;
        warunek=false;
        //resetowanie tablic
        for(i=1;i<10;i++)
            for(j=1;j<10;j++)
            {
                tabWsp[rozmiarWsp]=tabKwWsp[i-1][j-1]=i*10+j;
                *plansza[i-1][j-1].wartoscGra=*plansza[i-1][j-1].wartoscZnana=0;
                tabLog[i-1][j-1]=1;
                rozmiarWsp++;
            }
        //wypelnianie tablic
        liczZap=0;
        for(cyfra=1;cyfra<10;cyfra++)
        {
            i=0;
            while(i<9)
            {
                //warunek ktory wystepuje jesli braknie pasujacych wolnych miejsc
                if(!rozmiarWsp)
                {
                    liczZap++;
                    for(w=0;w<9;w++)
                        for(k=0;k<9;k++)
                            if(*plansza[w][k].wartoscGra==cyfra)
                                *plansza[w][k].wartoscGra=*plansza[w][k].wartoscZnana=0;
                    rozmiarWsp=i=0;
                    for(w=0;w<9;w++)
                        for(k=0;k<9;k++)
                            if(!*plansza[w][k].wartoscGra)
                            {
                                tabWsp[rozmiarWsp]=tabKwWsp[w][k];
                                tabLog[w][k]=1;
                                rozmiarWsp++;
                            }
                            else
                                tabLog[w][k]=0;
                }
                //losowanie wspolrzednych i wstawianie cyfr
                wsp = tabWsp[rand() % rozmiarWsp];
                w = (wsp/10)-1;
                k = (wsp % 10)-1;
                *(plansza[w][k].wartoscGra)=*(plansza[w][k].wartoscZnana)=cyfra;
                i++;
                wiersz(w,tabLog);
                kolumna(k,tabLog);
                kwadrat(w,k,tabLog);
                rozmiarWsp = 0;
                for(w=0;w<9;w++)
                    for(k=0;k<9;k++)
                        if (tabLog[w][k])
                        {
                            tabWsp[rozmiarWsp]=tabKwWsp[w][k];
                            rozmiarWsp++;
                        }
                if(liczZap>10)
                {
                    warunek=true;
                    break;
                }
            }
            if (warunek)
                break;
            rozmiarWsp=i=0;
            for(w=0;w<9;w++)
                for(k=0;k<9;k++)
                    if(!*plansza[w][k].wartoscGra)
                    {
                        tabWsp[rozmiarWsp]=tabKwWsp[w][k];
                        tabLog[w][k]=1;
                        rozmiarWsp++;
                    }
                    else
                        tabLog[w][k]=0;
        }

    }


    int indeks,licznik2;
    int licznik=0,licznik1=0;
    bool war;
    for(i=1;i<10;i++)
        for(j=1;j<10;j++)
        {
            tabWsp[rozmiarWsp]=tabKwWsp[i-1][j-1]=i*10+j;
            tabLog[i-1][j-1]=1;
            rozmiarWsp++;
        }
    switch (ile) {
    case 1:
        while(licznik<45)
        {
            indeks = rand() % rozmiarWsp;
            war = false;
            wsp = tabWsp[indeks];
            w = wsp/10 - 1;
            k = wsp%10 - 1;
            licznik2 = 0;
            for(i=0;i<9;i++)
                for(j=0;j<9;j++)
                {
                    if (*plansza[i][j].wartoscGra==*plansza[w][k].wartoscGra)
                        licznik2++;
                }


            if (licznik2>4)
                if((w>0)&&(w<8)&&(k>0)&&(k<8))
                {
                    liczZap = 0;
                    for(i=w-1;i<w+2;i++)
                        for(j=k-1;j<k+2;j++)
                            if(*plansza[i][j].wartoscGra)
                                liczZap++;
                    if(liczZap>4)
                    {
                        *plansza[w][k].wartoscGra = 0;
                        licznik++;
                        tabLog[w][k]=0;
                    }
                    else
                        tabLog[w][k]=0;
                        rozmiarWsp = 0;
                        for(i=0;i<9;i++)
                            for(j=0;j<9;j++)
                            {
                                if(tabLog[i][j])
                                {
                                    tabWsp[rozmiarWsp] = tabKwWsp[i][j];
                                    rozmiarWsp++;
                                }
                            }
                }
                else
                {
                    *plansza[w][k].wartoscGra = 0;
                    tabLog[w][k]=0;
                    for (i=indeks;i<rozmiarWsp-1;i++)
                        tabWsp[i]=tabWsp[i+1];
                    rozmiarWsp--;
                    licznik++;
                }
        }
        break;
    case 2:
        while(licznik<50)
        {
            indeks = rand() % rozmiarWsp;
            wsp = tabWsp[indeks];
            w = wsp/10 - 1;
            k = wsp%10 - 1;
            licznik2 = 0;
            for(i=0;i<9;i++)
                for(j=0;j<9;j++)
                {
                    if (*plansza[i][j].wartoscGra==*plansza[w][k].wartoscGra)
                        licznik2++;
                }
            if (licznik2>3)
                if((w>0)&&(w<8)&&(k>0)&&(k<8))
                {
                    liczZap = 0;
                    for(i=w-1;i<w+2;i++)
                        for(j=k-1;j<k+2;j++)
                            if(*plansza[i][j].wartoscGra)
                                liczZap++;
                    if(liczZap>4)
                    {
                        *plansza[w][k].wartoscGra = 0;
                        licznik++;
                        tabLog[w][k]=0;
                    }
                    else
                        tabLog[w][k]=0;
                    rozmiarWsp = 0;
                    for(i=0;i<9;i++)
                        for(j=0;j<9;j++)
                        {
                            if(tabLog[i][j])
                            {
                                tabWsp[rozmiarWsp] = tabKwWsp[i][j];
                                rozmiarWsp++;
                            }
                        }
                }
                else
                {
                    if (licznik1<25)
                    {
                        *plansza[w][k].wartoscGra = 0;
                        tabLog[w][k]=0;
                        licznik1++;
                        licznik++;
                    }
                    else
                        tabLog[w][k]=0;
                    rozmiarWsp = 0;
                    for(i=0;i<9;i++)
                        for(j=0;j<9;j++)
                        {
                            if(tabLog[i][j])
                            {
                                tabWsp[rozmiarWsp] = tabKwWsp[i][j];
                                rozmiarWsp++;
                            }
                        }

                }
        }
        break;
    case 3:
        while(licznik<53)
        {
            indeks = rand() % rozmiarWsp;
            wsp = tabWsp[indeks];
            w = wsp/10 - 1;
            k = wsp%10 - 1;
            licznik2 = 0;
            for(i=0;i<9;i++)
                for(j=0;j<9;j++)
                {
                    if (*plansza[i][j].wartoscGra==*plansza[w][k].wartoscGra)
                        licznik2++;
                }
            if (licznik2>2)
                if((w>0)&&(w<8)&&(k>0)&&(k<8))
                {
                    liczZap = 0;
                    for(i=w-1;i<w+2;i++)
                        for(j=k-1;j<k+2;j++)
                            if(*plansza[i][j].wartoscGra)
                                liczZap++;
                    if(liczZap>3)
                    {
                        *plansza[w][k].wartoscGra = 0;
                        licznik++;
                        tabLog[w][k]=0;
                    }
                    else
                        tabLog[w][k]=0;
                    rozmiarWsp = 0;
                    for(i=0;i<9;i++)
                        for(j=0;j<9;j++)
                        {
                            if(tabLog[i][j])
                            {
                                tabWsp[rozmiarWsp] = tabKwWsp[i][j];
                                rozmiarWsp++;
                            }
                        }
                }
                else
                {
                    if (licznik1<20)
                    {
                        *plansza[w][k].wartoscGra = 0;
                        tabLog[w][k]=0;
                        licznik1++;
                        licznik++;
                    }
                    else
                        tabLog[w][k]=0;
                    rozmiarWsp = 0;
                    for(i=0;i<9;i++)
                        for(j=0;j<9;j++)
                        {
                            if(tabLog[i][j])
                            {
                                tabWsp[rozmiarWsp] = tabKwWsp[i][j];
                                rozmiarWsp++;
                            }
                        }

                }
        }
        break;
    default:
        break;
    }
    delete[] tabWsp;
    for(i=0;i<9;i++)
        delete[] *(tabLog+i);
    for(i=0;i<9;i++)
        delete[] *(tabKwWsp+i);
    delete[] tabLog;
    delete[] tabKwWsp;
}


/* ?????????? */

//            if(licznik2>4)
//            {
//                for(i=0;i<9;i++)
//                    if(tabLog[i][k])
//                        licznik1++;
//                if(licznik1>4)
//                    war = true;
//                licznik1 = 0;
//                for(i=0;i<9;i++)
//                    if(tabLog[w][i])
//                        licznik1++;
//                if(licznik1>4)
//                    war = true;
//                if(war)
//                {
//                    plansza[w][k].wartoscGra = 0;
//                    licznik++;
//                    tabLog[w][k]=0;
//                }
//                else
//                {
//                    tabLog[w][k] = 0;
//                    wiersz(w,tabLog);
//                    kolumna(k,tabLog);
//                }

//                rozmiarWsp = 0;
//                for(i=0;i<9;i++)
//                    for(j=0;j<9;j++)
//                    {
//                        if(tabLog[i][j])
//                        {
//                            tabWsp[rozmiarWsp] = tabKwWsp[i][j];
//                            rozmiarWsp++;
//                        }
//                    }
