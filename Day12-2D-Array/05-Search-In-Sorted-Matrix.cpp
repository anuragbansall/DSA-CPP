#include <iostream>
using namespace std;

void searchInSortedMatrix(int matrix[][4], int n, int m, int key);

int main()
{
    int matrix[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    int n = sizeof(matrix) / sizeof(matrix[0]);
    int m = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    searchInSortedMatrix(matrix, n, m, key);

    return 0;
}

// Stair Case Search
void searchInSortedMatrix(int matrix[][4], int n, int m, int key)
{
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        int cell = matrix[row][col];
        if (cell == key)
        {
            cout << "Key found at row " << row << " and column " << col << endl;
            return;
        }
        else if (cell < key)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    cout << "Key not found in the matrix" << endl;
}
// Time Complexity: O(n + m)