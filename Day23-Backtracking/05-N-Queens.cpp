#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> &board);
void nQueens(vector<vector<char>> &board, int row);
bool isSafe(vector<vector<char>> &board, int row, int col);

int main(void)
{
    /*
        Place N queens on an NxN chessboard such that no two queens attack each other.

        N = 4
        . Q . .
        . . . Q
        Q . . .
        . . Q .
    */

    int n = 4;

    vector<vector<char>> board(n, vector<char>(n, '.'));
    nQueens(board, 0);

    return 0;
}

void printBoard(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void nQueens(vector<vector<char>> &board, int row)
{
    if (row == board.size())
    {
        printBoard(board);
        return;
    }

    // For now lets assume that we have to place queen in each row

    for (int col = 0; col < board.size(); col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            nQueens(board, row + 1);
            board[row][col] = '.';
        }
    }
} // Time Complexity - O(N!) and Space Complexity - O(N^2)

bool isSafe(vector<vector<char>> &board, int row, int col)
{
    // Check for the same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // Check for the same row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 'Q')
        {
            return false;
        }
    }

    // Check for the left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // Check for the right diagonal
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
} // Time Complexity - O(N^2) and Space Complexity - O(1)