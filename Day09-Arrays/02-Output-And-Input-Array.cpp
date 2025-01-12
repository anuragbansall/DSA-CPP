#include <iostream>
using namespace std;

int main()
{
    // Inputting elements of the array using a loop
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index " << i << ": ";
        cin >> arr[i];
    }

    // Outputting elements of the array using a loop
    cout << "Elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}