#include <iostream>
#include "generator.h"
#include"sortowanie.h"

using namespace std;


int main()
{
	generujDane(1); // tworzenie po 1 tablic za zadanych rozmiarach, warto�� ustawiona na 1, poniewa� wczytujemy jedn� tablic�
					// podczas przeprowadzania test�w ten argument wynosi� 100
	
	cout << "PRZYKLADOWE ROZWIAZANIA DLA TABLICY O ROZMIARZE 100000" << endl;
	wczytaj(100000, 1); // wczytanie i sortowanie danych

	system("pause");
	return 0;
}
