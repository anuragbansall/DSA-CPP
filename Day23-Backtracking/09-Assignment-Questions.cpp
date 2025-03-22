#include <iostream>
#include <vector>
using namespace std;

void ratInAMaze(vector<vector<int>> &maze, vector<vector<bool>> &visited, int x, int y, string path);
void keypadCombinations(string digits, vector<string> &keypad, string output, int index);
bool knightsTour(vector<vector<int>> &board, int x, int y, int move);

int main(void)
{
    /*
        Question 1: Rat in a Maze
        You are given a starting position for a rat which is stuck in a maze at an initial point (0,0)
        (the maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a square matrix of order N*N where the cells with value 0 represent the maze’s blocked locations
        while value 1 is the open/available path that the rat can take to reach its destination.
        The rat's destination is at (N-1, N-1). Your task is to find all the possible paths that the rat can take to reach from source to destination in the maze. The possible directions that it can take to move in the maze are 'U' (up) i.e. (x, y-1), 'D' (down) i.e. (x, y+1), 'L' (left) i.e. (x-1, y),
        'R' (right) i.e. (x+1, y). (This problem is similar to Gridways.)

        Sample Input:
        int maze[][] = {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}
        };

        Sample Output:
        DDRDRR
        DRDDRR

        Hint:
        To track which cell has or has not been visited, create a NxN vector called visited.
        This vector will be initialized with false values for all cells & make the value for a
        particular cell to true when you have visited it.
    */
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze.size(), false));
    ratInAMaze(maze, visited, 0, 0, "");

    /*
        Question 2: Keypad Combinations
        Given a string containing digits from 2-9 inclusive, print all possible letter combinations
        that the number could represent. You can print the answer in any order. A mapping of digits
        to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

        Sample Input 1:
        digits = "23"

        Sample Output 1:
        "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"

        Sample Input 2:
        digits = "2"

        Sample Output 2:
        "a", "b", "c"

        Sample Input 3:
        digits = ""

        Sample Output 3:
        ""
    */

    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    keypadCombinations("23", keypad, "", 0);

    /*
        Question 3: Knight’s Tour
        Given a N*N board with the Knight placed on the first block of an empty board. Moving according
        to the rules of chess, knights must visit each square exactly once. Print the order of each cell
        in which they are visited.

        Sample Input 1:
        N = 8

        Sample Output 1:
        0 59 38 33 30 17 8 63
        37 34 31 60 9 62 29 16
        58 1 36 39 32 27 18 7
        35 48 41 26 61 10 15 28
        42 57 2 49 40 23 6 19
        47 50 45 54 25 20 11 14
        56 43 52 3 22 13 24 5
        51 46 55 44 53 4 21 12

        Hint:
        This problem is similar to N Queens.
    */

    int n = 8;
    vector<vector<int>> board(n, vector<int>(n, -1));
    knightsTour(board, 0, 0, 0);

    return 0;
}

void ratInAMaze(vector<vector<int>> &maze, vector<vector<bool>> &visited, int x, int y, string path)
{
    int n = maze.size();
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1)
    {
        cout << path << endl;
        return;
    }

    // move up
    if (x > 0 && maze[x - 1][y] == 1 && !visited[x - 1][y])
    {
        visited[x][y] = true;
        ratInAMaze(maze, visited, x - 1, y, path + "U");
        visited[x][y] = false;
    }

    // move down
    if (x < n - 1 && maze[x + 1][y] == 1 && !visited[x + 1][y])
    {
        visited[x][y] = true;
        ratInAMaze(maze, visited, x + 1, y, path + "D");
        visited[x][y] = false;
    }

    // move left
    if (y > 0 && maze[x][y - 1] == 1 && !visited[x][y - 1])
    {
        visited[x][y] = true;
        ratInAMaze(maze, visited, x, y - 1, path + "L");
        visited[x][y] = false;
    }

    // move right
    if (y < n - 1 && maze[x][y + 1] == 1 && !visited[x][y + 1])
    {
        visited[x][y] = true;
        ratInAMaze(maze, visited, x, y + 1, path + "R");
        visited[x][y] = false;
    }
}

void keypadCombinations(string digits, vector<string> &keypad, string output, int index)
{
    if (index == digits.size())
    {
        cout << output << endl;
        return;
    }

    string letters = keypad[digits[index] - '0'];
    for (int i = 0; i < letters.size(); i++)
    {
        keypadCombinations(digits, keypad, output + letters[i], index + 1);
    }
}

void printBoard(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool knightsTour(vector<vector<int>> &board, int x, int y, int move)
{
    int n = board.size();

    if (move == n * n - 1)
    {
        board[x][y] = move;
        printBoard(board);
        board[x][y] = -1;
        return true;
    }

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}; // Possible moves for the knight in x direction
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; // Possible moves for the knight in y direction

    board[x][y] = move;

    for (int i = 0; i < 8; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newY >= 0 && newX < n && newY < n && board[newX][newY] == -1)
        {
            if (knightsTour(board, newX, newY, move + 1))
            {
                return true;
            }
        }
    }

    board[x][y] = -1; // Backtrack
    return false;     // No solution found
}
