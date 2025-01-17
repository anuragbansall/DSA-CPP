#include <iostream>
#include <string>
using namespace std;

bool validAnagram(string str1, string str2);

int main()
{
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    if (validAnagram(str1, str2))
    {
        cout << "The strings are valid anagrams." << endl;
    }
    else
    {
        cout << "The strings are not valid anagrams." << endl;
    }

    return 0;
}

// Suppose all characters are lowercase alphabets
bool validAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }

    int count[26] = {0};

    // Count the frequency of characters in str1
    for (char ch : str1)
    {
        int pos = ch - 'a';
        count[pos]++;
    }

    // Compare the frequency of str1 and str2
    for (char ch : str2)
    {
        int pos = ch - 'a';
        if (count[pos] == 0)
        {
            return false;
        }
        count[pos]--;
    }

    return true; // All characters in str1 have the same frequency in str2
}