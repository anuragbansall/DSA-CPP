#include <iostream>
using namespace std;

int main(void)
{
    /*
        Question:
        Which is a better time complexity: O(n^2) or O(n!)?

        Answer: O(n^2) is better than O(n!) because O(n^2) is polynomial time complexity and O(n!) is factorial time complexity.
    */

    /*
        Question:
        Which is a better time complexity: O(2^n) or O(n^n)?

        Answer: O(2^n) is better than O(n^n) because O(2^n) is exponential time complexity and O(n^n) is super-exponential time complexity.
    */

    return 0;
}

/*
    Estimating Time Complexity Using Constraints on Coding Platforms
    When solving coding problems, you can estimate the required time complexity based on the given constraints:

    1. Operations per Second: Most platforms assume that a program can execute around 10^7 to 10^8 operations per second.

    2. Common Constraints and Expected Complexity:

    N ≤ 10^5  →  O(N) or O(N log N) is optimal.
    N ≤ 10^6  →  O(N) is feasible, but O(N log N) may work depending on the constant factors.
    N ≤ 10^8  →  O(log N) or O(1) is required (e.g., binary search, bitwise tricks).
    N ≤ 1000  →  O(N^2) is usually acceptable.
    N ≤ 100   →  O(N^3) may work.
    N ≤ 20    →  O(2^N) (backtracking, bitmasking) may be feasible.
    N ≤ 10    →  O(N!) can be considered.

    3. Checking Edge Cases: Always analyze the worst-case scenario to ensure the solution runs within the time limit.
*/
