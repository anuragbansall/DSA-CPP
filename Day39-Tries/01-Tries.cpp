#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// TrieNode
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children; // char -> TrieNode mapping
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

// Trie Implementation
class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *node = root;

        for (char c : word)
        {
            if (node->children.count(c) == 0)
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }

        node->isEndOfWord = true;
    }

    bool search(const string &word)
    {
        TrieNode *node = root;

        for (char c : word)
        {
            if (node->children.count(c) == 0)
            {
                return false;
            }
            node = node->children[c];
        }

        return node->isEndOfWord;
    }
};

int main(void)
{
    vector<string> words = {"cat", "car", "dog", "dove"};
    // Create a trie and insert words into it
    Trie trie;

    // Insert words into the trie
    for (const auto &word : words)
        trie.insert(word);

    // Search for words in the trie
    cout << "Searching for 'cat': " << (trie.search("cat") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'car': " << (trie.search("car") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'dog': " << (trie.search("dog") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'dove': " << (trie.search("dove") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'catapult': " << (trie.search("catapult") ? "Found" : "Not Found") << endl;

    return 0;
}

/*
    Trie Data Structure:
    - A trie, also known as a prefix tree, is a tree-like data structure used to efficiently store and retrieve keys in a dataset of strings. It is commonly used for tasks such as autocomplete, spell checking, and IP routing.
    - Each node in a trie represents a single character of a string, and the edges between nodes represent the next character in the string. The root node represents an empty string, and each path from the root to a leaf node represents a complete string in the dataset.
    - Tries provide efficient search, insertion, and deletion operations, with a time complexity of O(m), where m is the length of the string being searched, inserted, or deleted. This makes them particularly useful for applications that involve a large number of strings with common prefixes.

    Example of a Trie:
    Consider the following set of strings: "cat", "car", "dog", "dove". The trie for this set of strings would look like this:

        (root)
        /   \
       c     d
      /       \
     a         o
    / \       / \
   t   r     g   v
                  \
                   e

    - Tries is  k-ary(generic) Tree
    - Each node can have up to k children, where k is the number of possible characters in the alphabet. For example, if we are working with lowercase English letters, k would be 26.
*/