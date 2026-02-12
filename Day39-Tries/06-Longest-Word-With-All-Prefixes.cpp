#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class TrieNode
{
public:
    map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

void dfs(TrieNode *node, string currentWord, string &longestWord)
{
    if (currentWord.length() > longestWord.length() ||
        (currentWord.length() == longestWord.length() && currentWord < longestWord))
    {
        longestWord = currentWord;
    }

    for (const auto &child : node->children)
    {
        if (child.second->isEndOfWord)
        {
            dfs(child.second, currentWord + child.first, longestWord);
        }
    }
}

string longestWordWithAllPrefixes(vector<string> &words)
{
    TrieNode *root = new TrieNode();

    // Build the Trie
    for (const string &word : words)
    {
        TrieNode *currentNode = root;
        for (char c : word)
        {
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                currentNode->children[c] = new TrieNode();
            }
            currentNode = currentNode->children[c];
        }
        currentNode->isEndOfWord = true;
    }

    string longestWord = "";

    for (const auto &child : root->children)
    {
        if (child.second->isEndOfWord)
        {
            dfs(child.second, string(1, child.first), longestWord);
        }
    }

    return longestWord;
}

int main(void)
{
    /*
        Longest Word With All Prefixes Problem:
        Given an array of strings words, find the longest string in words such that every prefix of it is also in words.

        Example 1:
        Input: words = ["a","banana","app","appl","ap","apply","apple"]
        Output: "apple"
        Explanation: "apple" is the longest word in words where every prefix is also in words.
        "app" is a prefix of "apple", and "appl" is a prefix of "apple", and "ap" is a prefix of "apple", and "a" is a prefix of "apple".

        Example 2:
        Input: words = ["w","wo","wor","worl", "world"]
        Output: "world"
        Explanation: "world" is the longest word in words where every prefix is also in words.
        "w" is a prefix of "world", "wo" is a prefix of "world", "wor" is a prefix of "world", and "worl" is a prefix of "world".

        Approach:
        1. Build a Trie from the given list of words.
        2. Perform a Depth-First Search (DFS) on the Trie to find the longest word that has all its prefixes in the Trie.
            - During the DFS, keep track of the current word being formed and update the longest word found so far.
            - Only continue the DFS if the current node represents the end of a valid word (i.e., isEndOfWord is true).
        3. Return the longest word found.
    */

    vector<string> words1 = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << "Longest Word With All Prefixes: " << longestWordWithAllPrefixes(words1) << endl; // Output: "apple"

    vector<string> words2 = {"w", "wo", "wor", "worl", "world"};
    cout << "Longest Word With All Prefixes: " << longestWordWithAllPrefixes(words2) << endl; // Output: "world"

    return 0;
}