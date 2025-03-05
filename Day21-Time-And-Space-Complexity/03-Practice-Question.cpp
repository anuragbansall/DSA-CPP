#include <iostream>
using namespace std;

int main(void)
{

    /*
        Practice Question 1: Calculate the time complexity of the following code:

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // constant work
            }
        }

        Answer: O(n^2) // Because there are two nested loops and both are running n times.
        // (n*(n-1)/2) = n^2/2 - n/2 = O(n^2)
    */

    /*
        Practice Question 2: Calculate the time complexity of the following code:

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // constant work
            }
        }

        Answer: O(n^2) // Because there are two nested loops and both are running n times.
        // (n*(n-1)/2) = n^2/2 - n/2 = O(n^2)
    */

    /*
        Practice Question 3: Calculate the time complexity of the following code:

        for (int i = 0; i < n; i += k)
        {
            for (int j = 0; j <= k; j++)
            {
                // constant work
            }
        }

        Answer: O(n) // Because the outer loop is running n/k times and the inner loop is running k times.
        // n/k * k = n
    */

    return 0;
}