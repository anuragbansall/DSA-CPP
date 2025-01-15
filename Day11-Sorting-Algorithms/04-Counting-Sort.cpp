#include <iostream>
#include <climits>
using namespace std;

void countingSort(int *arr, int n);
void printArr(int *arr, int n);

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArr(arr, n);
    countingSort(arr, n);
    cout << "Sorted array: ";
    printArr(arr, n);

    return 0;
}

void countingSort(int *arr, int n)
{
    int freq[100000] = {0};
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    // Count the frequency of each element
    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        freq[current]++;
        minVal = min(minVal, current);
        maxVal = max(maxVal, current);
    }

    for (int i = minVal, j = 0; i <= maxVal; i++)
    {
        while (freq[i] > 0)
        {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
}
// Time Complexity: 0(n + k), where k is the range of the input

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}