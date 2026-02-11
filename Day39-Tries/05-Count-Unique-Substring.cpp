#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

int countUniqueSubstrings(string str)
{
    TrieNode *root = new TrieNode();
    int count = 0;

    // Generate all possible substrings and insert them into the Trie
    for (int i = 0; i < str.length(); i++)
    {
        TrieNode *current = root;

        for (int j = i; j < str.length(); j++)
        {
            char c = str[j];

            if (current->children.find(c) == current->children.end())
            {
                current->children[c] = new TrieNode();
                count++;
            }

            current = current->children[c];
        }
    }

    return count + 1; // +1 for the empty substring
}

int main(void)
{
    /*
        Count Unique Substring Problem:
        Given a string, count total distinct substring
        Input: "ababa"
        Output: 10
        Explanation: Distinct substrings are "", "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", "ababa"

        Approach:
        1. Create a Trie data structure to store substrings.
        2. Generate all possible substrings of the input string and insert them into the Trie.
        3. Count the number of unique substrings by counting the number of nodes in the Trie.
    */

    string str = "ababa";
    int result = countUniqueSubstrings(str);
    cout << "Total distinct substrings: " << result << endl;

    str = "abc";
    result = countUniqueSubstrings(str);
    cout << "Total distinct substrings: " << result << endl;

    return 0;
}