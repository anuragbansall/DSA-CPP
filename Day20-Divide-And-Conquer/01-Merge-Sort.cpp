#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &arr, int left, int right);
void merge(vector<int> &arr, int left, int mid, int right);
void printArray(vector<int> &arr);

int main(void)
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}

/*
    Divide and Conquer:
        - Divide the problem into smaller subproblems
        - Conquer the subproblems by solving them recursively
        - Combine the solutions to the subproblems to solve the original problem
        - Merge Sort, Quick Sort, Binary Search, Strassen's Matrix Multiplication, Closest Pair of Points, etc are some of the examples of Divide and Conquer

    Merge Sort:
        - It is a sorting algorithm that follows the Divide and Conquer strategy
        - It divides the array into two halves, sorts the two halves independently, and then merges the two halves
        - The merge() function is used to merge the two halves
        - The merge() function takes two arrays as input and merges them into a single sorted array
        - The merge() function uses two pointers to compare the elements of the two arrays and then copies the smaller element to the result array
        - The time complexity of Merge Sort is O(n log n)
        - The space complexity of Merge Sort is O(n)

        Steps:
            1. Divide the array into two halves
            2. Sort the two halves independently
            3. Merge the two halves

*/

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return; // Base case
    }

    int mid = left + (right - left) / 2; // Mid pointer

    mergeSort(arr, left, mid);      // Sort the left half
    mergeSort(arr, mid + 1, right); // Sort the right half

    merge(arr, left, mid, right); // Merge the two arrays
} // Time Complexity: O(n log n)

void merge(vector<int> &arr, int left, int mid, int right)
{
    int i = left;     // Left Start pointer
    int j = mid + 1;  // Right Start pointer
    vector<int> temp; // Temporary array to store the sorted elements

    // Merge the two sorted halves
    while (i <= mid && j <= right) // Compare the elements of the two halves
    {
        if (arr[i] <= arr[j]) // Copy the smaller element
        {

            temp.push_back(arr[i++]);
        }
        else
        {

            temp.push_back(arr[j++]);
        }
    }

    // Copy remaining elements of the left half
    while (i <= mid)
    {

        temp.push_back(arr[i++]);
    }

    // Copy remaining elements of the right half
    while (j <= right)
    {

        temp.push_back(arr[j++]);
    }

    // Copy back to original array
    for (int i = left, key = 0; i <= right; i++)
    {
        arr[i] = temp[key++];
    }
} // Time Complexity: O(n)

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}