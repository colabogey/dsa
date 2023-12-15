
#include "mergesort.h"
#include <iostream>

// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Function to merge the two haves arr[l..m]
// and arr[m+1..r] of array arr[] 
void Merger::merge(int arr[], int l, int m, int r)
{
	int k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays 
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for(int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(int j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	// Merge the temp arrays
	// back into arr[l..r]
	int i = 0;
	int j = 0;
	k = l;
	
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements
	// of L[], if there are any 
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements
	// of R[], if there are any 
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void Merger::mergeSort(int array[], int const begin, int const end) {
    // Returns recursively
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void Merger::printArray(int array[], int const size) {
    for (auto i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

/*
// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is " << endl;
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array is " << endl;
    printArray(arr, arr_size);
    return 0;
}
*/


