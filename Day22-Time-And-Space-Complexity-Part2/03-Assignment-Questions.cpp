#include <iostream>
using namespace std;

int main(void)
{
    /*
        Question: Find the Time Complexity of the following:

        a)
        int i, j, k = 0;
        for (i = n / 2; i <= n; i++) {
            for (j = 2; j <= n; j = j * 2) {
                k = k + n / 2;
            }
        }
        A. O(n)
        B. O(N log N)
        C. O(n^2)
        D. O(n^2 Log n)

        Answer: Option B. O(N log N) is the correct answer.
        // Because the outer loop runs in O(n) and the inner loop runs in O(log n).

        b)
        for (int i = 0; i < n; i++) {
            i *= k;
        }
        Here, k is some constant value
        A. O(n)
        B. O(k)
        C. O(logk n) (= log n of base k)
        D. O(logn k) (= log k of base n)

        Answer: Option C. O(logk n) is the correct answer.
        // Because the value of i is multiplied by k in each iteration, which is equivalent to taking the log of i to the base k.

        c)
        Algorithm A and B have a worst-case running time of O(n) and O(log n), respectively. Therefore, algorithm B always runs faster than algorithm A.
        A. True
        B. False

        Answer: Option B. False is the correct answer.
        // The statement is false because the worst-case running time of an algorithm does not guarantee that it will always run faster than another algorithm with a different time complexity.

        d)
        Find the time & space complexity of floorSqrt function in the following code to calculate square root of a number:
        int floorSqrt(int x) {
            if (x == 0 || x == 1) return x;
            int i = 1, result = 1;
            while (result <= x) {
                i++;
                result = i * i;
            }
            return i - 1;
        }
        int main() {
            int x = 11;
            cout << floorSqrt(x);
            return 0;
        }

        Answer: O(sqrt(n)) is the time complexity and O(1) is the space complexity.
        // The function calculates the square root of a number using a while loop that runs until the square of i is less than or equal to x.

        e)
        Find the time & space complexity of the following code:
        int a = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = n; j > i; --j) {
                a = a + i + j;
            }
        }

        Answer: O(n^2) is the time complexity and O(1) is the space complexity.
        // The code contains two nested loops that iterate over the range of n, resulting in a time complexity of O(n^2).
    */

    return 0;
}