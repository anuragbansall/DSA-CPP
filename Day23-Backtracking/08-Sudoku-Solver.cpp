#include <iostream>
#include <vector>
using namespace std;

bool sudokuSolver(vector<vector<int>> &board, int row, int col);
void printBoard(vector<vector<int>> &board);
bool isSafe(vector<vector<int>> &board, int row, int col, int num);

int main(void)
{
    /*
        Sudoku is a 9x9 matrix in which every row, column and each 3x3 submatrix contains all numbers from 1 to 9 only once.
        Write a program to solve a Sudoku puzzle by filling the empty cells.
    */

    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    bool isSolved = sudokuSolver(board, 0, 0);

    if (!isSolved)
    {
        cout << "No solution exists!" << endl;
    }

    return 0;
}

bool sudokuSolver(vector<vector<int>> &board, int row, int col)
{
    if (row == 9)
    {
        printBoard(board);
        return true;
    }

    int nextRow = row, nextCol = col + 1;

    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (board[row][col] != 0)
    {
        return sudokuSolver(board, nextRow, nextCol);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;
            if (sudokuSolver(board, nextRow, nextCol))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(vector<vector<int>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            cout << "---------------------\n";
        }
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> &board, int row, int col, int num)
{
    // Check in row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }

    // Check in column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    // Check in 3x3 submatrix
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}