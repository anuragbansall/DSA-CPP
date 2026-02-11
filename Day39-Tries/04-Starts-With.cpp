#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;
    int count;

    TrieNode()
    {
        isEndOfWord = false;
        count = 0;
    }
};

bool startsWith(const vector<string> &words, const string &prefix)
{
    TrieNode *root = new TrieNode();

    // Build the Trie
    for (const string &word : words)
    {
        TrieNode *current = root;

        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
    }

    // Traverse the Trie using the characters of the prefix
    TrieNode *current = root;
    for (char c : prefix)
    {
        if (current->children.find(c) == current->children.end())
        {
            return false; // Prefix not found in Trie
        }
        current = current->children[c];
    }

    return true;
}

int main(void)
{
    /*
        Starts With Problem:
        Given a array of strings words and a string prefix, return true if there is a string in words that starts with prefix, and false otherwise.

        Example 1:
        Input: words = ["apple", "app", "mango", "man", "woman"]
        prefix = "app"
        Output: true
        Explanation: "apple" and "app" both start with "app".

        Example 2:
        Input: words = ["apple", "app", "mango", "man", "woman"]
        prefix = "moon"
        Output: false
        Explanation: There is no string in words that starts with "moon".

        Explanation:
        1. Build a Trie from the given list of words.
        2. Traverse the Trie using the characters of the prefix.
        3. If we can successfully traverse the Trie for all characters of the prefix, it means there is at least one word in the Trie that starts with the given prefix, and we return true. Otherwise, we return false.
    */

    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    string prefix1 = "app";
    string prefix2 = "moon";

    cout << startsWith(words, prefix1) << endl; // Output: true
    cout << startsWith(words, prefix2) << endl; // Output: false

    return 0;
}