#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

map<int, int> bottomView(Node *root)
{
    if (!root)
        return {};

    map<int, int> map;          // horizontal distance -> node value
    queue<pair<Node *, int>> q; // node and its horizontal distance

    q.push({root, 0});

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        Node *node = curr.first;
        int hd = curr.second;

        // Update the map with the current node for its horizontal distance
        map[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    return map;
}

vector<int> twoSum(vector<int> &arr, int target)
{
    unordered_map<int, int> mp; // element -> index

    for (int i = 0; i < arr.size(); i++)
    {
        int complement = target - arr[i];

        if (mp.find(complement) != mp.end())
        {
            return {mp[complement], i};
        }

        mp[arr[i]] = i;
    }

    return {}; // Return empty if no solution found
}

string frequencySort(string s)
{
    unordered_map<char, int> freqMap; // character -> frequency

    for (char c : s)
    {
        freqMap[c]++;
    }

    vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

    sort(freqVec.begin(), freqVec.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second > b.second; });

    string result;

    for (const auto &p : freqVec)
    {
        result.append(p.second, p.first);
    }

    return result;
}

string getHint(string secret, string guess)
{
    int bulls = 0, cows = 0;
    unordered_map<char, int> freqMap; // character -> frequency for secret

    for (int i = 0; i < secret.size(); i++)
    {
        if (secret[i] == guess[i])
        {
            bulls++;
        }
        else
        {
            freqMap[secret[i]]++;
        }
    }

    for (int i = 0; i < guess.size(); i++)
    {
        if (secret[i] != guess[i] && freqMap[guess[i]] > 0)
        {
            cows++;
            freqMap[guess[i]]--;
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main(void)
{
    /*
        Question 1: Bottom View of a Binary Tree

        Problem:
        Given a binary tree, print its bottom view — the set of nodes visible when the tree
        is viewed from the bottom. Print nodes from leftmost to rightmost horizontal distance.

        Example Tree:
                20
            /  \
            8   22
            / \    \
            5   3    25
            / \
            10 14

        Sample Output:
        Bottom view: 5 10 3 14 25

        Hint:
        Use vertical order traversal with horizontal distance (column) mapping and keep
        the deepest node for each column (e.g., BFS with level tracking).

        Question 2 : Two Sum

        Problem:
        Given an array of integers arr[] and an integer target, return indices of the two numbers such that they add up to target.
        You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

        Sample Input 1 : arr = [2, 7, 11, 15], target = 9
        Sample Output 1 : [0, 1]
        As arr[0] + arr[1] == 9, we return [0, 1].

        Sample Input 2 : arr = [3,2,4], target = 6
        Sample Output 2 : [1, 2]

        Question 3 : Sort by Frequency

        Problem:
        Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
        Return the sorted string. If there are multiple answers, return any of them.

        Sample Input 1 : s = "cccaaa"
        Sample Output 1 : "aaaccc"
        Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
        Note that "cacaca" is incorrect, as the same characters must be together.

        Sample Input 2 : s = "tree"
        Sample Output 2 :"eert"
        'e' appears twice while 'r' and 't' both appear once.
        So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer

        Question 4 : Bulls & Cows

        Problem:
        You are playing a game with your friend. You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with
        the following info:
        ● The number of "bulls", which are digits in the guess that are in the correct position.
        ● The number of "cows", which are digits in the guess that are in your secret number
        but are located in the wrong position. Specifically, the non-bull digits in the guess that
        could be rearranged such that they become bulls.
        Given the secret number secret and your friend's guess guess, return the hint for your
        friend's guess.

        The hint should be formatted as "xAyB", where x is the number of bulls and y is the number
        of cows. Note that both secret and guess may contain duplicate digits.

        Sample Input 1 : secret = "1807", guess = "7810"
        Sample Output 1 : "1A3B"
        Explanation: Bulls are highlighted with orange and cows are underlined:
        "1807", "7810"

        Sample Input 2 : secret = "1123", guess = "0111"
        Sample Output 2 : "1A1B"
        Explanation: Bulls are highlighted with orange and cows are underlined:
        "0111", (“0111” or “0111”)
    */

    // Answer 1: Bottom View of a Binary Tree
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    map<int, int> mp = bottomView(root);

    cout << "Bottom view: ";
    for (auto it : mp)
    {
        cout << it.second << " ";
    }
    cout << endl;

    // Answer 2: Two Sum
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(arr, target);

    cout << "Two Sum indices: ";
    for (int idx : result)
    {
        cout << idx << " ";
    }
    cout << endl;

    // Answer 3: Sort by Frequency
    string s = "tree";
    string sortedStr = frequencySort(s);
    cout << "Sorted by frequency: " << sortedStr << endl;

    // Answer 4: Bulls & Cows
    string secret = "1807";
    string guess = "7810";

    string hint = getHint(secret, guess);
    cout << "Bulls & Cows hint: " << hint << endl;

    return 0;
}