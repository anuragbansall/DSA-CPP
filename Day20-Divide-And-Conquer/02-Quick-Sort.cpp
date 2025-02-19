#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &arr, int left, int right);
int partition(vector<int> &arr, int left, int right);
void printArray(vector<int> &arr);

int main(void)
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Original array: \n";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: \n";
    printArray(arr);

    return 0;
}

/*
Quick Sort:
- Quick Sort is a divide and conquer algorithm.
        - It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot.
        - The sub-arrays are then sorted recursively.
        - There are many different versions of quickSort that pick pivot in different ways.
            - Pick last element as pivot. (This is probably the most common implementation)
            - Pick first element as pivot.
            - Pick a random element as pivot.
            - Pick median as pivot.

            - The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x.
        - All this should be done in linear time.
        */

void quickSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return; // Base case
    }

    int pivot = partition(arr, left, right); // get the index of the pivot element

    quickSort(arr, left, pivot - 1);  // sort the left sub-array
    quickSort(arr, pivot + 1, right); // sort the right sub-array
} // Time complexity: O(n log n) - average case, O(n^2) - worst case (when the array is already sorted)

int partition(vector<int> &arr, int left, int right)
{
    int i = left - 1;       // pointer to track the position of the pivot element
    int pivot = arr[right]; // select the last element as the pivot

    for (int j = left; j < right; j++) // iterate through the array
    {
        if (arr[j] <= pivot) // if the element at j is less than the pivot
        {
            i++;
            swap(arr[i], arr[j]); // swap the elements at i and j
        }
    }

    i++; // increment i to get the correct position of the pivot element

    swap(arr[i], arr[right]); // swap the element at i + 1 and the pivot element

    return i; // return the index of the pivot element
} // Time complexity: O(n)

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}