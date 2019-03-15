#ifndef QUICKSORT_H
#define QUICKSORT_H

void quick_sort(int *tablica, int lewy, int prawy)
{
	if (prawy == 0)
		return;
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

	if (p > lewy) quick_sort(tablica, lewy, p);
	if (l < prawy) quick_sort(tablica, l, prawy);
}

#endif QUICKSORT
