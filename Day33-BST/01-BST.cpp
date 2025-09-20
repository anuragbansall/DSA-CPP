#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

Node *buildBST(const vector<int> &values)
{
    Node *root = nullptr;

    for (int value : values)
    {
        root = insert(root, value);
    }

    return root;
}

int main(void)
{
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node *root = buildBST(values);

    return 0;
}

/*
    Binary Search Tree (BST):
    - BST is a special type of binary tree.
    - In a BST, for each node:
        - The left subtree contains only nodes with values less than the node's value.
        - The right subtree contains only nodes with values greater than the node's value.
        - Both the left and right subtrees must also be binary search trees.
    - This property makes BSTs efficient for searching, inserting, and deleting elements.
    - Average time complexity for search, insert, and delete operations is O(log n).
    - Inorder traversal of a BST yields the nodes in sorted order.

    Example of a BST:
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \    /
         4   7  13

    In this example:
    - The left subtree of the root node (8) contains values less than 8 (3, 1, 6, 4, 7).
    - The right subtree contains values greater than 8 (10, 14, 13).
    - This structure allows for efficient searching, as you can eliminate half of the tree at each step.

    Time Complexity:
    - Average Case: O(log n)
    - Worst Case: O(n) (occurs when the tree becomes unbalanced, resembling a linked list)
    - Space Complexity: O(h), where h is the height of the tree (due to recursion stack in operations)
*/