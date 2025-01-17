#include <iostream>
#include <string>
using namespace std;

int countVowels(string str);
bool stringSwap(string str1, string str2);

int main()
{
    /*
      Question 1:
      Count how many times lowercase vowels occurred in a string entered by the user.
    */
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int vowelCount = countVowels(str);
    cout << "Number of lowercase vowels in the string: " << vowelCount << endl;

    /*
      Question 2:
      You are given two strings s1 and s2 of equal length. A string swap is an operation
      where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
      Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings.
      Otherwise, return false.

      Example:
      Input: s1 = "bank", s2 = "kanb"
      Output: true
      Explanation: For example, swap the first character with the last character of s2 to make "bank".
    */
    string str1, str2;
    cout << "Enter two strings for comparison: ";
    cin >> str1 >> str2;

    bool canSwap = stringSwap(str1, str2);
    cout << "Can the strings be made equal with one swap? " << (canSwap ? "True" : "False") << endl;

    return 0;
}

int countVowels(string str)
{
    string vowels = "aeiou";
    int count = 0;
    for (char ch : str)
    {
        if (vowels.find(ch) != string::npos)
        {
            count++;
        }
    }

    return count;
}

bool stringSwap(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false; // Strings must be of the same length
    }

    // If both strings are already equal
    if (str1 == str2)
    {
        return true;
    }

    int diffCount = 0;
    char diffChar1 = '\0', diffChar2 = '\0';

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
        {
            diffCount++;
            if (diffCount == 1)
            {
                diffChar1 = str1[i];
                diffChar2 = str2[i];
            }
            else if (diffCount == 2)
            {
                if (str1[i] == diffChar2 && str2[i] == diffChar1)
                {
                    return true; // We found a valid swap
                }
                return false; // Found more than two differences or the swap is invalid
            }
            else
            {
                return false; // More than two differences
            }
        }
    }

    return false; // No valid swap found
}
