#include <iostream>
#include <string>
using namespace std;

void permutations(string str, string ans);

int main(void)
{
    /*
        Find & print all permutations of a given string.
        Eg. str = "ABC"
        Output: ABC, ACB, BAC, BCA, CAB, CBA
    */

    string str = "ABC";
    permutations(str, "");

    return 0;
}

void permutations(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string ros = str.substr(0, i) + str.substr(i + 1); // rest of the string
        permutations(ros, ans + ch);
    }
} // Time Complexity: O(n!) because there are n! permutations of a string of length n. Space Complexity: O(n) because of recursive stack space.