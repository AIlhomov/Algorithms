const bool SELECTION_IMPLEMENTED = false;
const bool INSERTION_IMPLEMENTED = true;

template<typename T> 
int binarySearch(T arr[], int nrOf, T elem)
{
	int low = 0;
	int high = nrOf - 1;

	while (low <= high) 
	{
		int mid = (low + high) / 2;

		if (arr[mid] == elem) return mid;


		if (arr[mid] > elem) high = mid - 1;
		if (arr[mid] < elem) low = mid + 1;
		
	}
	return -1;
}

template<typename T> 
void insertionSort(T arr[], int nrOf)
{
	for (int i = 1; i < nrOf; i++) {
		T key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

template<typename T> 
void selectionSort(T arr[], int nrOf)
{

} 

template<typename T>
void merge(T arr[], int startIndex, int midIndex, int endIndex)
{
	int leftNrOf = midIndex - startIndex + 1;
	int rightNrOf = endIndex - midIndex;
	T* left = new T[leftNrOf];
	T* right = new T[rightNrOf];

	for (int i = 0; i < leftNrOf; ++i)
		left[i] = arr[startIndex + i];
	for (int i = 0; i < rightNrOf; ++i)
		right[i] = arr[midIndex + 1 + i];

	int i = startIndex, j = 0, k = 0;
	while (j < leftNrOf && k < rightNrOf)
	{
		if (left[j] <= right[k])
		{
			arr[i] = left[j];
			++j;
		}
		else
		{
			arr[i] = right[k];
			++k;
		}
		++i;
	}
	while (j < leftNrOf)
	{
		arr[i] = left[j];
		++j;
		++i;
	}
	while (k < rightNrOf)
	{
		arr[i] = right[k];
		++k;
		++i;
	}
}

template<typename T> 
void mergeSortRecursive(T arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex) {
		int mid = (startIndex + endIndex) / 2;
		mergeSortRecursive(arr, startIndex, mid);
		mergeSortRecursive(arr, mid + 1, endIndex);
		merge(arr, startIndex, mid, endIndex);
	}
} 
 
template<typename T> 
void mergeSort(T arr[], int nrOf)
{
	mergeSortRecursive(arr, 0, nrOf - 1);
} 

