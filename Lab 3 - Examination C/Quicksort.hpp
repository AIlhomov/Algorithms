#ifndef QUICKSORT_H
#define QUICKSORT_H
template <typename T>
int partition(T arr[], int startIndex, int endIndex)
{
	T pivot = arr[startIndex];
	int i = startIndex;
	for (int j = startIndex + 1; j <= endIndex; j++)
	{
		if (arr[j] < pivot)
		{
			std::swap(arr[j], arr[++i]);
		}
	}
	std::swap(arr[startIndex], arr[i]);
	return i;
}


template <typename T>
void quickSort(T arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int pivotIndex = partition(arr, startIndex, endIndex);
		quickSort(arr, startIndex, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, endIndex);
	}

}

template <typename T>
void quickSort(T arr[], int nrOf)
{
	quickSort(arr, 0, nrOf - 1);
}
#endif