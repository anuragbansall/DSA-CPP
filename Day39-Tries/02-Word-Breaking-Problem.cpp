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

    TrieNode()
    {
        isEndOfWord = false;
    }
};

bool wordBreak(string s, vector<string> &wordDict)
{
    TrieNode *root = new TrieNode();

    // Build the Trie from the word dictionary
    for (const string &word : wordDict)
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
        current->isEndOfWord = true;
    }

    // DP
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true; // Base case: empty string can be segmented

    for (int i = 0; i < s.size(); i++)
    {
        if (!dp[i])
            continue; // If the current position cannot be segmented, skip

        TrieNode *current = root;
        for (int j = i; j < s.size(); j++)
        {
            char c = s[j];
            if (current->children.find(c) == current->children.end())
                break; // If the character is not in the Trie, break
            current = current->children[c];
            if (current->isEndOfWord)
            {
                dp[j + 1] = true; // Mark the position after the end of the word as true
            }
        }
    }

    return dp[s.size()]; // if last position is true, it means the string can be segmented
}

int main(void)
{
    /*
        Word Breaking Problem:
        Given a string and a dictionary of words, determine if the string can be segmented into a space-separated sequence of one or more dictionary words.

        Example:
        Input: s = "leetcode", wordDict = ["leet", "code"]
        Output: true
        Explanation: Return true because "leetcode" can be segmented as "leet code".

        Input: s = "applepenapple", wordDict = ["apple", "pen"]
        Output: true
        Explanation: Return true because "applepenapple" can be segmented as "apple pen apple". Note that you are allowed to reuse a dictionary word.

        Approach:
        1. Build a Trie from the given dictionary of words.
        2. Use a recursive function to check if the string can be segmented by traversing the Trie.
    */

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = wordBreak(s, wordDict);
    cout << (result ? "true" : "false") << endl;

    s = "applepenapple";
    wordDict = {"apple", "pen"};
    result = wordBreak(s, wordDict);
    cout << (result ? "true" : "false") << endl;

    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    result = wordBreak(s, wordDict);
    cout << (result ? "true" : "false") << endl;

    return 0;
}