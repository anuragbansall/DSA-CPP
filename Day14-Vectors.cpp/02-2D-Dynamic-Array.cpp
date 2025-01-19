#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int **matrix = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    // Input the elements of the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter the element at index (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }

    // Output the elements of the matrix
    cout << "The elements of the matrix are: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}