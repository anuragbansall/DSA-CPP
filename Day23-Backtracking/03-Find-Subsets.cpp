#include <iostream>
#include <string>
using namespace std;

void findSubsets(string str, string subSet);

int main(void)
{
    // Find and print all subsets of a string
    string str = "abc";
    findSubsets(str, "");

    return 0;
}

void findSubsets(string str, string subSet)
{

    int n = str.length();

    if (n == 0)
    {
        cout << subSet << endl;
        return;
    }

    findSubsets(str.substr(1, n - 1), subSet + str[0]); // yes call
    findSubsets(str.substr(1, n - 1), subSet);          // no call
} // Time Complexity: O(2^n), Space Complexity: O(n)