#include <iostream>
#include <climits>
using namespace std;

void printArr(int *arr, int n);
void bubbleSort(int *arr, int n);
void selectionSort(int *arr, int n);
void insertionSort(int *arr, int n);
void countingSort(int *arr, int n);

int main()
{
    /*
        Question 1: Use the following sorting algorithms to sort an array in DESCENDING order:
        a. Bubble Sort
        b. Selection Sort
        c. Insertion Sort
        d. Counting Sort
        You can use this array as an example: [3, 6, 2, 1, 8, 7, 4, 5, 3, 1]
    */
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArr(arr, n);

    cout << "Descending Sorted array using Bubble Sort: ";
    bubbleSort(arr, n);
    printArr(arr, n);

    cout << "Descending Sorted array using Selection Sort: ";
    selectionSort(arr, n);
    printArr(arr, n);

    cout << "Descending Sorted array using Insertion Sort: ";
    insertionSort(arr, n);
    printArr(arr, n);

    cout << "Descending Sorted array using Counting Sort: ";
    countingSort(arr, n);
    printArr(arr, n);

    return 0;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] < current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current; // Insert the current at its correct position
    }
}

void countingSort(int *arr, int n)
{
    int freq[10000] = {0};
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    for (int i = maxVal, j = 0; i >= minVal; i--)
    {
        while (freq[i] > 0)
        {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
}