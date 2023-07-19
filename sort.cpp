// C++ program for Merge Sort
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> burbleSort(vector<int> &arr) {
    for (int i=0;i<arr.size()-1;i++) {
        for (int j=i;j<arr.size();j++) {
            if (arr[j] > arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }
        }
    }
    return arr;
}

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
    // so phan tu arr1 = mid - left + 1
    // so phan tu arr2 = right - mid

	int const slarr1 = mid - left + 1;
	int const slarr2 = right - mid;

	// Create temp arrays
	auto *leftArray = new int[slarr1],
		*rightArray = new int[slarr2];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < slarr1; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < slarr2; j++)
		rightArray[j] = array[mid + 1 + j];

	auto i = 0, j = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	while (i < slarr1 && j < slarr2) {
		if (leftArray[i] <= rightArray[j]) {
			array[indexOfMergedArray] = leftArray[i];
			i++;
		}
		else {
			array[indexOfMergedArray] = rightArray[j];
			j++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (i < slarr1) {
		array[indexOfMergedArray] = leftArray[i];
		i++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (j < slarr2) {
		array[indexOfMergedArray] = rightArray[j];
		j++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const left, int const right)
{
	if (left >= right) return;

	int mid = (right + left) / 2;
	mergeSort(array, left, mid);
	mergeSort(array, mid + 1, right);
	merge(array, left, mid, right);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	// int arr[100];
    // srand(time(NULL));
    // cout << "Given array is \n";
    // for (int i = 0;i<100;i++) {
    //     arr[i] = rand() % 1000;
    //     cout << arr[i] << "  ";
    // }
	// // int arr_size = sizeof(arr) / sizeof(arr[0]);

	// mergeSort(arr, 0, 100 - 1);

	// cout << "\nSorted array is \n";
	// printArray(arr, 100);


    // burbleSort:
    vector<int> v = {1,3,2,5,7,8,10,9};
    burbleSort(v);

    for (auto x : v) {
        cout << x << " ";
    }
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
