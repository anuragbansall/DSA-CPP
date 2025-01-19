#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "The elements of the matrix are: " << endl;
    // Using for loop
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // uisng for-of loop
    // for (vector<int> row : matrix)
    // {
    //     for (int element : row)
    //     {
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}

/*
    2D Vector:
    - A 2D vector is a vector of vectors.
    - It is a data structure used to represent matrices in C++.
    - A 2D vector is a vector that contains multiple vectors, where each vector represents a row of the matrix.
    - The elements of the 2D vector are stored in contiguous memory locations.
    - The size of the 2D vector can be changed dynamically.
    - Syntax:
        vector<vector<data_type>> vector_name;
    - Example:
        vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Note:
    In 2D Array number of columns is fixed but in 2D Vector number of columns can be changed dynamically for each row.
*/