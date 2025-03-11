#include <iostream>
using namespace std;

int main(void)
{

    return 0;
}

/*
    Backtracking:
        - Backtracking is a systematic algorithmic technique that builds potential solutions incrementally. At each step, if it determines that the current candidate cannot possibly lead to a valid complete solution, it abandons (backtracks) and tries a different path. This method is often implemented recursively, exploring possible options until a complete solution is found or all possibilities are exhausted.
        - Backtracking is like exploring a maze: you try one path, and if it leads to a dead end, you go back and try a different route.

    Types of Backtracking:
        1. Decision:
            - In this type of backtracking, we make a decision at each step to include or exclude an element.
            - Example: Subset, Permutation, Combination, N-Queens, Sudoku, etc.
        2. Optimization:
            - In this type of backtracking, we try to find the best solution among all possible solutions.
            - Example: Hamiltonian Cycle, Travelling Salesman Problem, etc.
        3. Enumeration:
            - In this type of backtracking, we try to find all possible solutions.
            - Example: N-Queens, Sudoku, etc.
*/
