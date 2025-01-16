#include <iostream>
using namespace std;

void spiralMatrix(int arr[][4], int n, int m);

int main()
{
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr[0]) / sizeof(arr[0][0]);

    spiralMatrix(arr, n, m);

    return 0;
}

void spiralMatrix(int arr[][4], int n, int m)
{

    int srow = 0, erow = n - 1;
    int scol = 0, ecol = m - 1;

    while (srow <= erow && scol <= ecol)
    {
        // Print top row
        for (int i = scol; i <= ecol; i++)
        {
            cout << arr[srow][i] << " ";
        }
        srow++;

        // Print right column
        for (int i = srow; i <= erow; i++)
        {
            cout << arr[i][ecol] << " ";
        }
        ecol--;

        // Print bottom row
        if (srow <= erow) // Check to avoid double printing
        {
            for (int i = ecol; i >= scol; i--)
            {
                cout << arr[erow][i] << " ";
            }
            erow--;
        }

        // Print left column
        if (scol <= ecol) // Check to avoid double printing
        {
            for (int i = erow; i >= srow; i--)
            {
                cout << arr[i][scol] << " ";
            }
            scol++;
        }
    }
    cout << endl;
}