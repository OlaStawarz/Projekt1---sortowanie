#ifndef GENERATOR_H
#define GENERATOR_H

#include <fstream>
#include <string>

using namespace std;

template <class int>
int* generujTablice(int rozmiar)
{
    int* tablica = new int[rozmiar];

    if(tablica==nullptr)
    {
        return nullptr;
    }

    for (int i=0; i<rozmiar; i++)
    {
        tablica[i]=(rand()%1000)/10.0;
    }

    return tablica;
}

void zapis(int* tablica, int rozmiar)
{
    fstream plik;
    string sciezka = to_string(rozmiar)+".txt";
    plik.open(sciezka, fstream::out|fstream::app);

    for (int i=0; i<rozmiar; i++)
    {
        plik<<tablica[i]<< " ";
    }
    plik<<endl;
    plik.close();
}

void generujDane (int ilosc)
{
    int rozmiar_tablicy[3] = {10, 20, 30};
    int* tablica;

    for(int i=0; i<3; i++)
    {
       for(int j=0; j<ilosc; j++)
        {
        tablica = generujTablice<int>(rozmiar_tablicy[i]);
        zapis(tablica,rozmiar_tablicy[i]);

        }
    }
    delete[] tablica;
}



#endif // GENERATOR_H
