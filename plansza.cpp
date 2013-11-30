#include "plansza.h"

Plansza::Plansza(void)

{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            tablica[i][j]=0;
}
/**
 * @brief Plansza::Wczytaj     zapisuje cyfre do tablicy
 * @param w     numer wiersza
 * @param k     numer kolumny
 * @param liczba    zapisywana liczba
 */
void Plansza::Wczytaj(int w, int k, int liczba)
{

        tablica[w][k]=liczba;


}
/**
 * @brief Plansza::Czysc   zeruje tablice
 */
void Plansza::Czysc()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            tablica[i][j]=0;

}

