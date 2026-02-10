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

vector<string> findShortestUniquePrefixes(const vector<string> &words)
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
            current->count++; // Increment count of words passing through this node
        }
        current->isEndOfWord = true;
    }

    vector<string> result;

    // Find shortest unique prefix for each word
    for (const string &word : words)
    {
        TrieNode *current = root;
        string prefix = "";
        for (char c : word)
        {
            prefix += c;
            current = current->children[c];
            if (current->count == 1) // If count is 1, this prefix is unique
            {
                break; // Found the unique prefix
            }
        }
        result.push_back(prefix);
    }

    return result;
}

int main(void)
{
    /*
        Prefix Problem:
        Find shortest unique prefix for every word in the given list of words. (no word is prefix of another word)
        Input: ["zebra", "dog", "duck", "dove"]
        Output: ["z", "dog", "du", "dov"]
        Explanation: The shortest unique prefix for "zebra" is "z" because 'z' is not the prefix of any other word. The shortest unique prefix for "dog" is "dog" because 'd' and 'do' are prefixes of "duck" and "dove". The shortest unique prefix for "duck" is "du" because 'd' is a prefix of "dog" and 'do' is a prefix of "dove". The shortest unique prefix for "dove" is "dov" because 'd' and 'do' are prefixes of "dog" and "duck".

        Approach:
        1. Build a Trie from the given list of words.
        2. For each word, traverse the Trie until we find a node that has only one child. The path from the root to this node will be the shortest unique prefix for that word.
    */

    vector<string> words = {"zebra", "dog", "duck", "dove"};
    vector<string> uniquePrefixes = findShortestUniquePrefixes(words);
    for (const string &prefix : uniquePrefixes)
    {
        cout << prefix << " ";
    }
    cout << endl;

    words = {"apple", "ape", "april"};
    uniquePrefixes = findShortestUniquePrefixes(words);
    for (const string &prefix : uniquePrefixes)
    {
        cout << prefix << " ";
    }
    cout << endl;

    return 0;
}