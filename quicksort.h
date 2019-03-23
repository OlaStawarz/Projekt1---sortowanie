#ifndef QUICKSORT_H
#define QUICKSORT_H


int podzial(int *tablica, int lewy, int prawy)
{
	int os = tablica[(lewy + prawy) / 2]; // wybór osi odniesienia
	int p = prawy;
	int l = lewy;
	int pom;
	while (l <= p)
	{
		while (tablica[l] < os) l++; // gdy element po lewej stornie mniejszy od osi -> szukaj dalej
		while (tablica[p] > os) p--; // gdy element po prawej stornie wiekszy od osi -> szukaj dalej
		if (l <= p)
		{
			pom = tablica[l]; // zamiana miejscami
			tablica[l] = tablica[p];
			tablica[p] = pom;
			l++;
			p--;
		}
	}
	return l;
}

void quick_sort(int* tablica, int lewy, int prawy) {
	if (lewy < prawy)
	{
		int q = podzial(tablica, lewy, prawy);
		quick_sort(tablica, lewy, q - 1);
		quick_sort(tablica, q + 1, prawy);
	}
}

//void quick_sort(int *tablica, int lewy, int prawy)
//{
//	if (prawy == 0)
//		return;
//	int os = tablica[(lewy + prawy) / 2]; // wybór osi odniesienia
//	int p = prawy;
//	int l = lewy;
//	int pom;
//	while (l <= p)
//	{
//		while (tablica[l] < os) l++; // gdy element po lewej stornie mniejszy od osi -> szukaj dalej
//		while (tablica[p] > os) p--; // gdy element po prawej stornie wiekszy od osi -> szukaj dalej
//		if (l <= p)
//		{
//			pom = tablica[l]; // zamiana miejscami
//			tablica[l] = tablica[p];
//			tablica[p] = pom;
//			l++;
//			p--;
//		}
//	}
//
//	if (p > lewy) quick_sort(tablica, lewy, p);
//	if (l < prawy) quick_sort(tablica, l, prawy);
//}






















//void quick_sort(int *tab, int lewy, int prawy)
//{
//	if (prawy <= lewy) return;
//
//	int i = lewy - 1, j = prawy + 1,
//		pivot = tab[(lewy + prawy) / 2]; //wybieramy punkt odniesienia
//
//	while (1)
//	{
//		//szukam elementu wiekszego lub rownego piwot stojacego
//		//po prawej stronie wartosci pivot
//		while (pivot > tab[++i]);
//
//		//szukam elementu mniejszego lub rownego pivot stojacego
//		//po lewej stronie wartosci pivot
//		while (pivot < tab[--j]);
//
//		//jesli liczniki sie nie minely to zamieñ elementy ze soba
//		//stojace po niewlasciwej stronie elementu pivot
//		if (i <= j)
//			//funkcja swap zamienia wartosciami tab[i] z tab[j]
//			swap(tab[i], tab[j]);
//		else
//			break;
//	}
//
//	if (j > lewy)
//		quick_sort(tab, lewy, j);
//	if (i < prawy)
//		quick_sort(tab, i, prawy);
//}

//int quick_sort(int* tab, int lewy, int prawy) {
//
//	int i = lewy; //to pierwszy element tablicy z lewej
//	int j = prawy; //to pierwszy element tablicy z prawej
//	int tmc;
//
//	int pivot = tab[(lewy + prawy) / 2]; //pivot to œrodkowy element
//
//	while (i <= j) {
//
//		while (tab[i] < pivot)
//		{
//			i++; //przesuwamy siê o pozycjê do przodu
//		}
//		while (tab[j] > pivot)
//		{
//			j--; //przesuwamy siê o pozycjê do ty³u
//		}
//
//		if (i <= j) {
//			tmc = tab[i];
//			tab[i] = tab[j];
//			tab[j] = tmc;
//			i++;
//			j--;
//		}
//
//	};
//
//	if (lewy < j) {
//		quick_sort(tab, lewy, j);
//	}
//
//	if (i < prawy) {
//		quick_sort(tab, i, prawy);
//	}
//
//	return i;
//}

//int podzial(int *tablica, int lewy, int prawy)
//{
//	int os = tablica[(lewy + prawy) / 2]; // wybór osi odniesienia
//	int p = prawy;
//	int l = lewy;
//	int pom;
//	while (l <= p)
//	{
//		while (tablica[l] < os) l++; // gdy element po lewej stornie mniejszy od osi -> szukaj dalej
//		while (tablica[p] > os) p--; // gdy element po prawej stornie wiekszy od osi -> szukaj dalej
//		if (l <= p)
//		{
//			pom = tablica[l]; // zamiana miejscami
//			tablica[l] = tablica[p];
//			tablica[p] = pom;
//			l++;
//			p--;
//		}
//	}
//	return l;
//}
//
//void quick_sort(int* tablica, int lewy, int prawy) {
//	if (lewy < prawy)
//	{
//		int q = podzial(tablica, lewy, prawy);
//		quick_sort(tablica, lewy, q - 1);
//		quick_sort(tablica, q + 1, prawy);
//	}
//}

#endif QUICKSORT
