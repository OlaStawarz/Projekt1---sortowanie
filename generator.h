#ifndef GENERATOR_H
#define GENERATOR_H

#include <fstream>
#include <string>

using namespace std;

template <class var>
int* generujTablice(int rozmiar) // tworzenie tablicy dynamicznej o zadanym rozmiarze
{
	int* tablica = new int[rozmiar];

	if (tablica == nullptr) // zabezpieczenie przed wpisaniem zerowej wartosci
	{
		return nullptr;
	}

	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = (rand() % 1000 + 1); // jaki przyjac zakres??
	}

	return tablica;
}

void zapis(int* tablica, int rozmiar) // zapisywanie tablicy do pliku
{
	fstream plik;
	string sciezka = to_string(rozmiar) + ".txt"; // towrzenie pliku .txt o nazwie rownej rozmiarowi
	plik.open(sciezka, fstream::out | fstream::app);

	for (int i = 0; i < rozmiar; i++)
	{
		plik << tablica[i] << " ";
	}
	plik << endl;
	plik.close();
}

void generujDane(int ilosc) // ilosc - ile tablic o danym rozmiarze ma zostac utworzonych
{
	int rozmiartablicy[3] = {10, 20, 30};
	int* tablica;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < ilosc; j++)
		{
			tablica = generujTablice<int>(rozmiartablicy[i]);
			zapis(tablica, rozmiartablicy[i]);

		}
	}
	//delete[] tablica;
}



#endif GENERATOR_H
