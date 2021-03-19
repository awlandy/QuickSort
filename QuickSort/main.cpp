/* C++ implementation of QuickSort */
#include <iostream>
using namespace std;

bool DEBUG = true;

void swap(int*, int*);
int partition(int[], int, int);
void quickSort(int[], int, int);
void printArray(int[], int);

int main(int argc, char* argv[])
{
   
    if (argc > 1 && argv[1] == "-d") {
        DEBUG = true;
        cout << "Console log: Debug is on.\n";
    }

    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (DEBUG) {
        cout << "Intialize arr[" << n << "]: ";
        printArray(arr, n);
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot 
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]);
            if (DEBUG) {
                cout << "Console log: swapping elements " << i << " and " << j << "\n";
                cout << "After swapping: ";
                printArray(arr, high + 1);
            }
               
        }
    }
    swap(&arr[i + 1], &arr[high]);
    if (DEBUG) {
        cout << "Console log: swapping elements " << i + 1 << " and " << high << "\n";
        cout << "After swapping: ";
        printArray(arr, high + 1);
    }
        
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    cout << "{";
    for (i = 0; i < size; i++)
        if (i != size - 1)
            cout << arr[i] << ", ";
        else
            cout << arr[i] << "}\n";
}