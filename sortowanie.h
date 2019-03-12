#ifndef SORTOWANIE_H
#define SORTOWANIE_H

#include<ctime>
#include "quicksort.h"

#include <fstream>
#include <string>

enum metoda
{
    QUICKSORT,
    SCALANIE,
    INTROSPEKTYWNE
};


double sortowanie(metoda metoda, int* tablica, int rozmiar)
{
    clock_t czasStart = clock();

    switch(metoda)
    {
    case QUICKSORT: //Quicksort
        quick_sort(tablica, 0, rozmiar-1);
        break;
    case SCALANIE:  //Scalanie
        break;
    case INTROSPEKTYWNE:
        break;  //Introspektywne

    }

    clock_t czasKoniec = clock();

    return (czasStart-czasKoniec)/CLOCKS_PER_SEC;
}

double przygotowanie(int* tablica, int rozmiar)
{
    int* pomocnicza = new int [rozmiar];
    double czas;
    pomocnicza=tablica;

    czas=sortowanie(QUICKSORT, pomocnicza, rozmiar);
    pomocnicza=tablica;

}

void wczytaj(int rozmiar, int ilosc)
{
    int* tablica = new int[rozmiar];
    fstream plik;
    string sciezka = to_string(rozmiar)+".txt";
    plik.open(sciezka, fstream::in);
    for(int j=0; j<ilosc; j++)
    {
      for(int i=0; i<rozmiar; i++)
    {
        plik>>tablica[i];
        cout << tablica[i] << " ";
    }
    przygotowanie(tablica, rozmiar);
    }

    plik.close();

}



#endif // SORTOWANIE
