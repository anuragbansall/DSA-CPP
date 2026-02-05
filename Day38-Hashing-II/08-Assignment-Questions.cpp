#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
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

        Question 2 :
        Two Sum
        Given an array of integers arr[] and an integer target, return indices of the two numbers such that they add up to target.
        You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

        Sample Input 1 : arr = [2, 7, 11, 15], target = 9
        Sample Output 1 : [0, 1]
        As arr[0] + arr[1] == 9, we return [0, 1].

        Sample Input 2 : arr = [3,2,4], target = 6
        Sample Output 2 : [1, 2]
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

    return 0;
}