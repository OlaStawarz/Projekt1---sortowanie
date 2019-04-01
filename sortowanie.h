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

/* Zmienne tp i duration to zmienne z biblioteki chrono, pozwalaj�cej mierzy� czas z wi�ksz� dok�adno�ci� */

void zapiszczas(duration d) // zapisz czasu do pliku
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
		quick_sort(pomocnicza, 0, rozmiar*stopnie[j] - 1); //przygotowanie tablicy, okre�lenie procentu wst�pnego posortowania, quicksort sortuje tablice
		                                                   // dla podanego parametru

		cout << nazwy[j] << endl;

		start = chrono::system_clock::now(); // algorytm quicksort
		quick_sort(pomocnicza, 0, rozmiar - 1); 
		d = chrono::system_clock::now() - start;
		cout << "Quicksort: " << d.count();
		zapiszczas(d);
		cout << endl;

		start = chrono::system_clock::now(); // algorytm mergesort
		merge_sort(pomocnicza, 0, rozmiar - 1);
		d = chrono::system_clock::now() - start;
		cout << "Sortowanie przez scalanie: " << d.count();
		zapiszczas(d);
		cout << endl;

		start = chrono::system_clock::now(); // algorytm introsort
		IntroSort(pomocnicza, rozmiar);
		d = chrono::system_clock::now() - start;
		cout << "Sortowanie introspektywne: " << d.count() << endl;
		zapiszczas(d);
		cout << endl;
	
	}
}

void sortowanie_odwrotne(int* tablica, int rozmiar) // wariant wst�pnego posortowania element�w w odwrotnej kolejno�ci
{
	int* pomocnicza = new int[rozmiar];

	cout << "Elementy w odwrotnej kolejnosci: " << endl;
	quick_sort(tablica, 0, rozmiar - 1); // sortowanie element�w w odwrotnej kolejno�ci
	for (int i = 0; i < rozmiar; i++)
	{
		pomocnicza[(rozmiar - 1 - i)] = tablica[i];
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
}

void wczytaj(int rozmiar, int ilosc) // funkcja wczytuj�ca tablice z pliku oraz odpowiadaj�ca za sortowanie
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
		sortowanie(tablica, rozmiar); // sortowanie 
		sortowanie_odwrotne(tablica, rozmiar); // sortowanie element�w w odwrotnej kolejno�ci
	}

	plik.close();

}

#endif SORTOWANIE_H

