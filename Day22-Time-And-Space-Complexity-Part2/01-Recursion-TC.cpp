#include <iostream>
using namespace std;

// Approach 1: Simple Recursive Summation
int sumRecursive(int n)
{
    if (n == 0)
    {
        return 0; // Base case: sum of zero elements is 0
    }
    return sumRecursive(n - 1) + n; // Recursive call with n-1, accumulating sum
}
// Time Complexity: O(n) (n recursive calls)
// Space Complexity: O(n) (due to recursive call stack)

// Approach 2: Exponential Recursive Growth
int exponentialRecursive(int n)
{
    if (n == 0)
    {
        return 1; // Base case: return 1 when n == 0
    }
    return exponentialRecursive(n - 1) + exponentialRecursive(n - 1); // Two recursive calls per call
}
// Time Complexity: O(2^n) (Each level doubles the recursive calls)
// Space Complexity: O(n) (Maximum depth of recursion tree)

int main()
{
    int x = 5;
    cout << "sumRecursive(" << x << "): " << sumRecursive(x) << endl;                 // Expected output: 15
    cout << "exponentialRecursive(" << x << "): " << exponentialRecursive(x) << endl; // Expected output: 32

    return 0;
}

/*
    Recursion Complexity Analysis:

    1. sumRecursive(n):
        - Total work: n + (n-1) + (n-2) + ... + 1
        - Recurrence Relation: T(n) = T(n-1) + 1
        - Time Complexity: O(n) (linear growth)
        - Space Complexity: O(n) (stack memory for recursive calls)

    2. exponentialRecursive(n):
        - Total work: 2^n - 1
        - Recurrence Relation: T(n) = 2T(n-1) + 1
        - Time Complexity: O(2^n) (exponential growth)
        - Space Complexity: O(n) (max depth of recursion tree)

    Space Complexity Analysis:
    - Maximum recursion depth * memory used per call.
*/
