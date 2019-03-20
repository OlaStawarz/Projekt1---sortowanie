#ifndef INTROSPEKTYWNE_H
#define INTROSPEKTYWNE_H


/*****Please include following header files*****/
// cmath
/***********************************************/

//static int Partition(int* data, int left, int right) {
//	int pivot = data[right];
//	int temp;
//	int i = left;
//
//	for (int j = left; j < right; ++j)
//	{
//		if (data[j] <= pivot)
//		{
//			temp = data[j];
//			data[j] = data[i];
//			data[i] = temp;
//			i++;
//		}
//	}
//
//	data[right] = data[i];
//	data[i] = pivot;
//
//	return i;
//}

int podzial(int *tablica, int lewy, int prawy)
{
	//if (prawy == 0)
		//return;
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

void QuickSort(int* tablica, int lewy, int prawy) {
	if (lewy < prawy)
	{
		int q = podzial(tablica, lewy, prawy);
		QuickSort(tablica, lewy, q - 1);
		QuickSort(tablica, q + 1, prawy);
	}
}

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

static void InsertionSort(int* data, int count) {
	for (int i = 1; i < count; ++i)
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

static void IntroSort(int* data, int count) {
	int partitionSize = podzial(data, 0, count - 1);

	if (partitionSize < 16)
	{
		InsertionSort(data, count);
	}
	else if (partitionSize > (2 * log(count)))
	{
		HeapSort(data, count);
	}
	else
	{
		QuickSort(data, 0, count - 1);
	}
}

#endif INTROSPEKTYWNE_H
