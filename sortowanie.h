#ifndef SORTOWANIE_H
#define SORTOWANIE_H

#include <chrono>
#include "quicksort.h"
#include "scalanie.h"

#include <fstream>
#include <string>

using namespace std;
using tp = std::chrono::time_point<std::chrono::system_clock>;
using duration = std::chrono::duration<float>;


void sortowanie(int* tablica, int rozmiar)
{
	int* pomocnicza = new int[rozmiar];
	double stopnie[4] = { 0, 0.25, 0.50, 0.75 };
	double czas;
	int wybor;
	tp start;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < rozmiar; i++) {
			pomocnicza[i] = tablica[i];
		}
		quick_sort(pomocnicza, 0, rozmiar*stopnie[j] - 1);
		/*for (int i = 0; i < rozmiar; i++) {
			cout << pomocnicza[i] << " ";
		}*/
		cout << endl;

		start = chrono::system_clock::now(); 
		quick_sort(pomocnicza, 0, rozmiar - 1); //<----tylko to mierzymy
		duration d = chrono::system_clock::now() - start;
		cout << d.count();

		//for (int i = 0; i < rozmiar; i++) {
		//	pomocnicza[i] = tablica[i];
		//	//cout << pomocnicza[i] << " ";
		//}
		quick_sort(pomocnicza, 0, rozmiar*stopnie[j] - 1);
		/*for (int i = 0; i < rozmiar; i++) {
			cout << pomocnicza[i] << " ";
		}*/
		cout << endl;
		merge_sort(pomocnicza, 0, rozmiar - 1);
	}
	
	
	delete[] pomocnicza;
	
}

void wczytaj(int rozmiar, int ilosc)
{
	int* tablica = new int[rozmiar];
	fstream plik;
	string sciezka = to_string(rozmiar) + ".txt";
	plik.open(sciezka, fstream::in);
	for (int j = 0; j < ilosc; j++)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			plik >> tablica[i];
			//cout << tablica[i] << " ";
		}
		cout << endl;
		sortowanie(tablica, rozmiar);
	}

	plik.close();

}





enum metoda
{
	QUICKSORT,
	SCALANIE,
	INTROSPEKTYWNE
};


double menu(metoda metoda, int* tablica, int rozmiar)
{
	clock_t czasStart = clock();
	//int metoda;

	/*switch(metoda)
	{
	case QUICKSORT: //Quicksort
		quick_sort(tablica, 0, rozmiar-1);
		break;
	case SCALANIE:  //Scalanie
		break;
	case INTROSPEKTYWNE:
		break;  //Introspektywne

	}*/

	clock_t czasKoniec = clock();

	return (czasStart - czasKoniec) / CLOCKS_PER_SEC;
}



#endif SORTOWANIE_H
