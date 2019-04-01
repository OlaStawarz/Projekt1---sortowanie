#include <iostream>
#include "generator.h"
#include"sortowanie.h"

using namespace std;


int main()
{
	generujDane(1); // tworzenie po 1 tablic za zadanych rozmiarach, wartoœæ ustawiona na 1, poniewa¿ wczytujemy jedn¹ tablicê
					// podczas przeprowadzania testów ten argument wynosi³ 100
	
	cout << "PRZYKLADOWE ROZWIAZANIA DLA TABLICY O ROZMIARZE 100000" << endl;
	wczytaj(100000, 1); // wczytanie i sortowanie danych

	system("pause");
	return 0;
}
