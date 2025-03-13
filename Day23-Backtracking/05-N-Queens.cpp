#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> &board);
void nQueens(vector<vector<char>> &board, int row);

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

    int n = 2;

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
        board[row][col] = 'Q';
        nQueens(board, row + 1);
        board[row][col] = '.';
    }
}