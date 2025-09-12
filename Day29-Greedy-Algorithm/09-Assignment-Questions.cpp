#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxBalancedStrings(string s)
{
    int balance = 0;
    int count = 0;

    for (char c : s)
    {
        if (c == 'L')
        {
            balance++;
        }
        else if (c == 'R')
        {
            balance--;
        }

        if (balance == 0)
        {
            count++;
        }
    }

    return count;
}

string largestOddNumber(string num)
{
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 != 0) // Check if the digit is odd
        {
            return num.substr(0, i + 1); // Return substring from start to this index
        }
    }

    return ""; // No odd digit found
}

string smallestString(int n, int k)
{
    string result = "";

    while (n != 0)
    {
        int value = max(1, k - 26 * (n - 1));
        value = min(value, 26);

        char ch = 'a' + value - 1;

        result += ch;
        k -= value;
        n--;
    }

    return result;
}

int main(void)
{
    /*
        Question 1: Split a String in Balanced Strings
        Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
        Given a balanced string s, split it into some number of substrings such that:
        Each substring is balanced. Return the maximum number of balanced strings you can obtain.

        Example:
        Input: s = "RLRRLLRLRL"
        Output: 4
        Explanation: Can be split into "RL", "RRLL", "RL", "RL", each substring contains the same number of 'L' and 'R'

        Approach:
        1. Iterate through the string, maintaining a balance counter.
        2. Increment the counter for 'L' and decrement for 'R'.
        3. Each time the counter reaches zero, it indicates a balanced substring.
        4. Count these occurrences to get the maximum number of balanced substrings.
        5. Return the count.
    */

    string s = "RLRRLLRLRL";

    cout << "Maximum number of balanced strings: " << maxBalancedStrings(s) << endl;

    /*
        Question 2: Largest Odd Number in String
        You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
        A substring is a contiguous sequence of characters within a string.

        Example:
        Input: num = "52"
        Output: "5"
        Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

        Approach:
        1. Traverse the string from the end to the beginning.
        2. Check each character to see if it is an odd digit (1, 3, 5, 7, 9).
        3. The first odd digit encountered will be the last character of the largest odd substring
        4. Return the substring from the start of the string to this character.
        5. If no odd digit is found, return an empty string.
    */

    string num = "52";

    cout << "Largest odd number: " << largestOddNumber(num) << endl;

    /*
        Question 3: Smallest String With a Given Numeric Value

        The numeric value of a lowercase character is its position in the alphabet (1-indexed), so 'a' = 1, 'b' = 2, ..., 'z' = 26.
        The numeric value of a string is the sum of its characters' numeric values.

        Given two integers n and k, return the lexicographically smallest string of length n with a numeric value equal to k.

        Note: A string x is lexicographically smaller than string y if x comes before y in dictionary order.

        Example:
        Input: n = 3, k = 27
        Output: "aay"
        Explanation: The numeric value is 1 + 1 + 25 = 27, and "aay" is the smallest string of length 3 with this value.
    */

    int n = 3, k = 27;

    cout << "Smallest string: " << smallestString(n, k) << endl;

    return 0;
}