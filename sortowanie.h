#ifndef SORTOWANIE_H
#define SORTOWANIE_H

#include <chrono>
#include "quicksort.h"
#include "scalanie.h"
#include "introspektywne.h"

#include <fstream>
#include <string>

using namespace std;
using tp = chrono::time_point<std::chrono::system_clock>;
using duration = chrono::duration<float>;

tp start;
duration d;

void zapiszczas(duration d)
{
	fstream plik;
	string sciezka = "zapisczasu.txt"; // tworzenie pliku .txt
	plik.open(sciezka, fstream::out | fstream::app);
	if (plik.is_open())
	{
		plik << d.count();
		plik << endl;
	}
	else
		cout << "Nie udalo sie zapisac do pliku";
	
	plik.close();
}


void sortowanie(int* tablica, int rozmiar)
{
	int* pomocnicza = new int[rozmiar];
	double stopnie[7] = { 0, 0.25, 0.50, 0.75, 0.95, 0.99, 0.997 };
	string nazwy[7] = { "Wszystkie elementy losowe: ",
						"25% pierwszych elementow posortowane: ",
						"50% pierwszych elementow posortowane: ",
						"75% pierwszych elementow posortowane: ",
						"95% pierwszych elementow posortowane: ",
						"99% pierwszych elementow posortowane: ",
						"99.7% pierwszych elementow posortowane: " };

	for (int j = 0; j < 7; j++)
	{
		for (int i = 0; i < rozmiar; i++) {
			pomocnicza[i] = tablica[i];
		}
		quick_sort(pomocnicza, 0, rozmiar*stopnie[j] - 1); //przygotowanie tablicy
		/*for (int i = 0; i < rozmiar; i++) {
			cout << pomocnicza[i] << " ";
		}*/
		
		cout << nazwy[j] << endl;
		
		start = chrono::system_clock::now(); 
		quick_sort(pomocnicza, 0, rozmiar - 1); // tylko to mierzymy
		/*for (int i = 0; i < rozmiar; i++) {
			cout << pomocnicza[i] << " ";
		}*/
		d = chrono::system_clock::now() - start;
		cout << "Quicksort: " << d.count();
		zapiszczas(d);
		cout << endl;
				
		start = chrono::system_clock::now();
		merge_sort(pomocnicza, 0, rozmiar - 1);
		d = chrono::system_clock::now() - start;
		cout << "Sortowanie przez scalanie: " << d.count();
		cout << endl;
		
		start = chrono::system_clock::now();
		IntroSort(pomocnicza, rozmiar);
		d = chrono::system_clock::now() - start;
		cout << "Sortowanie introspektywne: " << d.count() << endl;
		cout << endl;
	}
	
	cout << "Elementy w odwrotnej kolejnosci: " << endl;
	quick_sort(tablica, 0, rozmiar - 1);
	for (int i = 0; i < rozmiar; i++)
	{
		pomocnicza[(rozmiar-1-i)] = tablica[i];
	}
	
	start = chrono::system_clock::now();
	quick_sort(pomocnicza, 0, rozmiar - 1);
	d = chrono::system_clock::now() - start;
	cout << "Quicksort: " << d.count();
	zapiszczas(d);
	cout << endl;

	for (int i = 0; i < rozmiar; i++)
	{
		pomocnicza[(rozmiar - 1 - i)] = tablica[i];
	}

	start = chrono::system_clock::now();
	merge_sort(pomocnicza, 0, rozmiar - 1);
	d = chrono::system_clock::now() - start;
	cout << "Sortowanie przez scalanie: " << d.count();
	zapiszczas(d);
	cout << endl;

	for (int i = 0; i < rozmiar; i++)
	{
		pomocnicza[(rozmiar - 1 - i)] = tablica[i];
	}

	start = chrono::system_clock::now();
	IntroSort(pomocnicza, rozmiar);
	d = chrono::system_clock::now() - start;
	cout << "Sortowanie introspektywne: " << d.count();
	zapiszczas(d);
	cout << endl;



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
		}
		cout << endl;
		sortowanie(tablica, rozmiar);
	}

	plik.close();

}

#endif SORTOWANIE_H
