#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b= temp;
}

// Selection Sort:
vector<int> SelectionSort(vector<int> &arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    return arr;
}

// burble sort:
vector<int> BurbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return arr;
}

// Insertion Sort:
vector<int> InsertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i=1;i<n;i++) {
        for (int j = i; j>=1;j--) {
            if (arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }
        }
    }
    return arr;
}

//Merge_Sort
void merge(int arr[], int l, int m, int r) {
    vector<int> a(arr+l, arr+m+1);
    vector<int> b(arr+m+1, arr+r+1);

    int slarr1 = m-l+1;
    int slarr2 = r - m;

    int i=0; int j=0;
    while (i < slarr1 && j < slarr2)
    {
        if (a[i] <= b[j]) {
            arr[l] = a[i]; i++;l++; 
        } else {
            arr[l] = b[j]; j++;l++;
        }
    }
    while (i< slarr1)
    {
        arr[l] = a[i]; i++;l++;     
    }
    while (j < slarr2)
    {
        arr[l] = b[j]; j++;l++;
    }
}

void Merge(int array[], int const left, int const mid,
           int const right)
{
    int const slArr1 = mid - left + 1;
    int const slArr2 = right - mid;
 
    // Create temp arrays
    auto *Arr1 = new int[slArr1],
         *Arr2 = new int[slArr2];
 
    // Copy data to temp arrays Arr1[] and Arr2[]
    for (auto i = 0; i < slArr1; i++)
        Arr1[i] = array[left + i];
    for (auto j = 0; j < slArr2; j++)
        Arr2[j] = array[mid + 1 + j];
 
    auto i = 0, j = 0;
    int index = left;
 
    // Merge the temp arrays back into array[left..right]
    while (i < slArr1 && j < slArr2) {
        if (Arr1[i] <= Arr2[j]) {
            array[index] = Arr1[i];
            i++;
        }
        else {
            array[index] = Arr2[j];
            j++;
        }
        index++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (i < slArr1) {
        array[index] = Arr1[i];
        i++;
        index++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (j < slArr2) {
        array[index] = Arr2[j];
        j++;
        index++;
    }
    delete[] Arr1;
    delete[] Arr2;
}
 
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void merge_Sort(int array[], int const begin, int const end)
{
    if (begin >= end) return;

    int mid = (end + begin) / 2;
    merge_Sort(array, begin, mid);
    merge_Sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main() {
    vector<int> arr = {1,3,5,2,6,7,4,10,15,11};

    for (int i = 0; i< arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout << endl;
    // vector<int>::iterator ptr;
    // for (ptr = arr.begin(); ptr < arr.end(); ptr++) {
    //     cout << *ptr << " ";
    // }

    SelectionSort(arr);
    BurbleSort(arr);
    InsertionSort(arr);


    for (int i = 0; i< arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout << endl;



    int n = 100;
    int a[100];
    srand(time(NULL));
    // current Array;
    for (int i=0;i<n;i++) {
        a[i] = rand()%1000;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    merge_Sort(a,0,n-1);
    cout<< " array after change: " <<endl;

    for (int i=0;i<n;i++) {
        cout << a[i] << " ";
    }


    // return 0;
}