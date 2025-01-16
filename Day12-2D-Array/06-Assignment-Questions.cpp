#include <iostream>
using namespace std;

int printNumberOfSevens(int arr[][3], int n, int m);
int sumOfRow(int arr[][3], int n, int m, int row);
void printTransposeMatrix(int arr[][3], int n, int m);

int main()
{
    /*
    Question 1:
    Print the number of all 7's that are in the 2D array.
    Example:
    Input - int arr[][] = {{4, 7, 8}, {8, 8, 7}};
            n = 2, m = 3
    Output - 2
    */
    int arr1[][3] = {{4, 7, 8}, {8, 8, 7}};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int m1 = sizeof(arr1[0]) / sizeof(arr1[0][0]);
    cout << "Number of 7's in arr1: " << printNumberOfSevens(arr1, n1, m1) << endl;

    /*
    Question 2:
    Print out the sum of the numbers in the second row of the “nums” array.
    Example:
    Input - int nums[][] = {{1, 4, 9}, {11, 4, 3}, {2, 2, 3}};
    Output - 18
    */
    int nums2[][3] = {{1, 4, 9}, {11, 4, 3}, {2, 2, 3}};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    int m2 = sizeof(nums2[0]) / sizeof(nums2[0][0]);
    cout << "Sum of numbers in the second row of nums2: " << sumOfRow(nums2, n2, m2, 1) << endl;

    /*
    Question 3:
    Write a program to find the transpose of a matrix.
    What is Transpose?
    Transpose of a matrix is the process of swapping the rows to columns.
    For a 2x3 matrix,
    Matrix:
    a11 a12 a13
    a21 a22 a23
    Transposed Matrix:
    a11 a21
    a12 a22
    a13 a23
    */
    int arr3[][3] = {{1, 4, 9}, {11, 4, 3}, {2, 2, 3}};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int m3 = sizeof(arr3[0]) / sizeof(arr3[0][0]);
    printTransposeMatrix(arr3, n3, m3);

    return 0;
}

int printNumberOfSevens(int arr[][3], int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 7)
            {
                count++;
            }
        }
    }

    return count;
}

int sumOfRow(int arr[][3], int n, int m, int row)
{
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
        sum += arr[row][j];
    }

    return sum;
}

void printTransposeMatrix(int arr[][3], int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}