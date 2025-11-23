#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        cout << "Heapifying at index: " << i << endl;
        heapify(arr, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--)
    {
        cout << "Extracting element at index: " << i << endl;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(void)
{
    vector<int> arr = {1, 4, 2, 5, 3};
    int n = arr.size();

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    Heap Sort:
    Time Complexity: O(n log n)
    Space Complexity: O(1)

    Algorithm Steps:
    1. Build a max heap from the input data.
       - Start from the last non-leaf node and heapify each node up to the root.
       - if Size of arr = n
        - Node from index n/2 to n - 1 are leaf nodes.
        - Call heapify for nodes from index n/2 - 1 to 0.
    2. Swap the root of the max heap with the last element of the heap.
       - Reduce the heap size by one and heapify the root.
    3. Repeat step 2 until the heap size is greater than 1.
    4. The array is now sorted in ascending order.
*/