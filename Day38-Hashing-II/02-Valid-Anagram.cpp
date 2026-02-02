#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> charCount; // char -> frequency

    for (char c : s)
    {
        charCount[c]++;
    }

    for (char c : t)
    {
        if (charCount.find(c) == charCount.end() || charCount[c] == 0)
        {
            return false;
        }
        charCount[c]--;
    }

    return true;
}

int main(void)
{
    /*
        Given two strings s and t, return true if t is an anagram of s, and false otherwise.
        Example 1:
        Input: s = "anagram", t = "nagaram"
        Output: true
        Example 2:
        Input: s = "rat", t = "car"
        Output: false
    */

    string s = "race";
    string t = "care";

    if (isAnagram(s, t))
    {
        cout << t << " is an anagram of " << s << endl;
    }
    else
    {
        cout << t << " is not an anagram of " << s << endl;
    }

    return 0;
}