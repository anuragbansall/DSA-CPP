#include <iostream>
#include <vector>
using namespace std;

void incrementArr(vector<int> &arr, int i);
void printArr(vector<int> arr);

int main(void)
{
    vector<int> arr(5, 0);
    int n = arr.size();

    incrementArr(arr, 0);
    printArr(arr);

    return 0;
}

void incrementArr(vector<int> &arr, int i)
{
    if (i == arr.size()) // Base case
    {
        printArr(arr);
        return;
    }

    arr[i] = i + 1;           // Increment
    incrementArr(arr, i + 1); // Recurse
    arr[i] -= 2;              // Backtrack
}

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
    Backtracking on Arrays:
    - This example demonstrates a basic backtracking approach applied to an array:
        - We have an array of size n, and we want to increment each element by 1.
        - We start from the first element and increment it by 1.
        - We then move to the next element and increment it by 1.
        - We continue this process until we reach the end of the array.
        - Once we reach the end of the array, we print the array.
        - We then decrement the last element by 2 and backtrack to the previous element.
        - We continue this process until we reach the first element.
        - This example demonstrates how backtracking can be applied to arrays to explore different possibilities.
*/