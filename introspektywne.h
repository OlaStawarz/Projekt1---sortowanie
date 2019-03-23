#ifndef INTROSPEKTYWNE_H
#define INTROSPEKTYWNE_H

#define M_LN2 0.69314718

#include "quicksort.h"

//template <class var>
//void wstawianie(var *tab, int n)
//{
//	int tmc, j;
//	for (int i = 1; i < n; ++i)
//	{
//		tmc = tab[i];
//		j = i - 1;
//
//		while (j >= 0 && tab[j] > tmc)
//		{
//			tab[j + 1] = tab[j];
//			--j;
//		}
//		tab[j + 1] = tmc;
//	}
//}
//
//template <class var>
//void kopiec(var tab[], int n, int i)
//{
//
//	int j = i;
//	int lewy = i * 2 + 2;
//	int prawy = i * 2 + 1;
//
//	if ((prawy < n) && (tab[j] < tab[prawy]))
//	{
//		j = prawy;
//	}
//	if ((lewy < n) && (tab[j] < tab[lewy]))
//	{
//		j = lewy;
//	}
//
//	if (j != i)
//	{
//		int tmc = tab[i];
//		tab[i] = tab[j];
//		tab[j] = tmc;
//		kopiec(tab, n, j);
//	}
//}
//
//
//template <class var>
//void kopcowanie(var tab[], int n)
//{
//
//	int i;
//	int tmc;
//	for (int i = n / 2 - 1; i >= 0; i--)
//	{
//		kopiec(tab, n, i);
//	}
//
//	for (i = n - 1; i >= 0; i--) {
//
//		tmc = tab[i];
//		tab[i] = tab[0];
//		tab[0] = tmc;
//
//		kopiec(tab, i, 0);
//	}
//}
//
//
//
//template <class var>
//void IntroSort1(var *Array, int N, int M)
//{
//	int i;
//	if (M <= 0)
//	{
//		kopcowanie(Array, N);
//		return;
//	}
//	i = quick_sort(Array, 0, N - 1);
//	if (i > 9)
//		IntroSort1(Array, i, M - 1);
//	if (N - 1 - i > 9)
//		IntroSort1(Array + i + 1, N - 1 - i, M - 1);
//}
//
//template <class var>
//void IntroSort(var *Array, int N)
//{
//	IntroSort1(Array, N, (int)floor(2 * log(N) / M_LN2));
//	wstawianie(Array, N);
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
//void QuickSort(int* tablica, int lewy, int prawy) {
//	if (lewy < prawy)
//	{
//		int q = podzial(tablica, lewy, prawy);
//		QuickSort(tablica, lewy, q - 1);
//		QuickSort(tablica, q + 1, prawy);
//	}
//}

static void MaxHeapify(int* data, int heapSize, int index) {
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

	if (left < heapSize && data[left] > data[index])
		largest = left;
	else
		largest = index;

	if (right < heapSize && data[right] > data[largest])
		largest = right;

	if (largest != index)
	{
		int temp = data[index];
		data[index] = data[largest];
		data[largest] = temp;

		MaxHeapify(data, heapSize, largest);
	}
}

static void HeapSort(int* data, int count) {
	int heapSize = count;

	for (int p = (heapSize - 1) / 2; p >= 0; --p)
		MaxHeapify(data, heapSize, p);

	for (int i = count - 1; i > 0; --i)
	{
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		--heapSize;
		MaxHeapify(data, heapSize, 0);
	}
}

static void InsertionSort(int* data, int rozmiar) {
	for (int i = 1; i < rozmiar; ++i)
	{
		int j = i;

		while ((j > 0))
		{
			if (data[j - 1] > data[j])
			{
				data[j - 1] ^= data[j];
				data[j] ^= data[j - 1];
				data[j - 1] ^= data[j];

				--j;
			}
			else
			{
				break;
			}
		}
	}
}

static void IntroSort(int* data, int rozmiar) {
	int partitionSize = podzial(data, 0, rozmiar - 1);

	if (partitionSize < 16)
	{
		InsertionSort(data, rozmiar);
	}
	else if (partitionSize > (2 * log(rozmiar)))
	{
		HeapSort(data, rozmiar);
	}
	else
	{
		quick_sort(data, 0, rozmiar - 1);
	}
}

#endif INTROSPEKTYWNE_H
