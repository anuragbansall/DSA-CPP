#include <iostream>
using namespace std;

bool isArraySorted(int arr[], int n);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Is the array sorted? " << (isArraySorted(arr, n) ? "Yes" : "No") << endl;

    return 0;
}

bool isArraySorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }

    return arr[0] < arr[1] && isArraySorted(arr + 1, n - 1);
}