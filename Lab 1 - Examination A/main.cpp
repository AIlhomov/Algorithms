#include <iostream>
//#include "ExaminationA.hpp"
using namespace std;

template <typename T>
int binarySearch(T arr[], int s, int e, T elem) {

	if (s > e) return -1;
	int mid = (s + e) / 2;

	if (arr[mid] == elem) return mid;
	if (arr[mid] > elem) return binarySearch(arr, s, mid + 1, elem);
	if (arr[mid] < elem) return binarySearch(arr, mid - 1, e, elem);

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
int main() {

	int arr[] = { 543, 21, 2, 77, 932, 432, 122 };
	
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl << binarySearch(arr, 0, n, 432);







	return 0;
}