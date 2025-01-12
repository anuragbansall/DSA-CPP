#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {23, 45, 67, 89, 12, 34, 56, 78, 90, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0];
    int smallest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    cout << "Largest element in the array: " << largest << endl;
    cout << "Smallest element in the array: " << smallest << endl;

    return 0;
}