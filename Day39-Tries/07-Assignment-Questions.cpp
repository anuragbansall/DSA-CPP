#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    TrieNode *root = new TrieNode();
    map<TrieNode *, vector<string>> anagramGroups;

    for (const string &str : strs)
    {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());

        TrieNode *currentNode = root;
        for (char c : sortedStr)
        {
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                currentNode->children[c] = new TrieNode();
            }
            currentNode = currentNode->children[c];
        }
        currentNode->isEndOfWord = true;
        anagramGroups[currentNode].push_back(str);
    }

    vector<vector<string>> result;
    for (const auto &group : anagramGroups)
    {
        result.push_back(group.second);
    }

    return result;
}

int main(void)
{
    /*
        Group Anagrams Together Problem:
        Given an array of strings strs, group the anagrams together. You can return the answer in any order.
        An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

        Sample Input 1 : strs = ["eat","tea","tan","ate","nat","bat"]
        Sample Output 1 : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]

        Sample Input 2 : strs = [""]
        Sample Output 2 : [[""]]

        Sample Input 3 : strs = ["a"]
        Sample Output 3 : [["a"]]

        Approach (using Trie):
        1. Create a TrieNode class to represent each node in the trie.
        2. For each string in the input array, sort the characters of the string to get the anagram key.
        3. Insert the sorted string into the trie, and at the end of the insertion, mark the node as the end of a word and store the original string in a list at that node.
        4. After processing all strings, traverse the trie to collect the grouped anagrams from the nodes that are marked as end of word.
    */

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);
    for (const auto &group : groupedAnagrams)
    {
        cout << "[";
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << "]";
    }

    return 0;
}