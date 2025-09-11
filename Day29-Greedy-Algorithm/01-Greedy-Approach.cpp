#include <iostream>
using namespace std;

// Find largest element in an array using Greedy Approach
int findLargest(int arr[], int n);

int main(void)
{
    int arr[] = {3, 5, 7, 2, 8, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest = findLargest(arr, n);
    cout << "Largest element in the array is: " << largest << endl;

    return 0;
}

int findLargest(int arr[], int n)
{
    int largest = arr[0]; // Assume the first element is the largest

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i]; // Update largest if current element is greater
        }
    }

    return largest;
}

/*
    Greedy Approach:
    - A greedy algorithm is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most immediate benefit or the most optimal choice at that moment.
    - Make the greedy choice at each step.
    - Choose the local optimum & hope to reach the global optimum.
    - Greedy algorithms do not always yield the optimal solution for every problem, but they can be very efficient for certain types of problems.
*/