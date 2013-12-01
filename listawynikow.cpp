#include "listawynikow.h"
#include <fstream>

ListaWynikow::ListaWynikow()
{
    pierwszy = NULL;
    ostatni = NULL;
    liczba = 0;
}

ListaWynikow::~ListaWynikow()
{
    Wynik *iteracja = pierwszy;
    Wynik *iteracjanastepny = NULL;
    if(liczba)
        do
        {
            iteracjanastepny = iteracja->nastepny;
            delete iteracja;
            iteracja = iteracjanastepny;
        }while(iteracja != NULL);
    liczba = 0;
    pierwszy = ostatni = NULL;
}

void ListaWynikow::dodaj(Wynik *nowy)
{
//        Wynik *nowy = n;
        if (!liczba)
            pierwszy = ostatni = nowy;
        else
        {
            Wynik *indeksmin = NULL;
            Wynik *indeks = pierwszy;
            do
            {
                if(nowy->getMinuty()>indeks->getMinuty())
                {
                    indeksmin = indeks;
                    indeks = indeks->nastepny;
                }
                else
                {
                    if((nowy->getMinuty()==indeks->getMinuty()) && (nowy->getSekundy()>indeks->getSekundy()))
                    {
                        indeksmin = indeks;
                        indeks = indeks->nastepny;
                    }
                    else
                    {
                        if(indeks == pierwszy)
                        {
                            pierwszy = nowy;
                            pierwszy->nastepny = indeks;
                            break;
                        }

                        else
                        {
                            indeksmin->nastepny = nowy;
                            nowy->nastepny = indeks;
                            break;
                        }
                    }
                }
                if( indeks == NULL)
                {
                    indeksmin->nastepny = nowy;
                    nowy->nastepny = indeks;
                    ostatni = nowy;
                }
            }while (indeks!=NULL);
        }
        liczba++;
}

void ListaWynikow::wczytaj(char nazwa[])
{
    std::fstream dane;
    Wynik* wynik;
    char imie[30];
    int min,sek,i = 0,liczba;
    dane.open(nazwa,std::ios::in);
    dane>>liczba;
    do
    {
        if(!liczba)
            break;
        wynik = new Wynik();
        dane>> imie >> min >> sek;
        wynik->setImie(imie);
        wynik->setMinuty(min);
        wynik->setSekundy(sek);
        dodaj(wynik);
        i++;
    }while(i<liczba);
    dane.close();
}

void ListaWynikow::zapisz(char nazwa[])
{
    std::fstream plik;
    int i = 0;
    Wynik* indeks;
    indeks = pierwszy;
    plik.open(nazwa,std::ios::out | std::ios::trunc);
    if(liczba>9)
        plik<<10<<std::endl;
    else
        plik<<liczba<<std::endl;
    if(liczba)
        do
        {
            plik<< indeks->getImie().toStdString() <<" "<< indeks->getMinuty() <<" "<< indeks->getSekundy() << std::endl;
            indeks = indeks->nastepny;
            i++;
        }while((indeks!=NULL)&&(i!=10));
    plik.close();
}
