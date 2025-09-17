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

Node *buildTreeFromPreorder(vector<int> &preorder, int &index)
{
    if (index >= preorder.size() || preorder[index] == -1)
    {
        index++;
        return nullptr;
    }

    Node *newNode = new Node(preorder[index++]);

    newNode->left = buildTreeFromPreorder(preorder, index);
    newNode->right = buildTreeFromPreorder(preorder, index);

    return newNode;
}

int transformToSumTree(Node *root)
{
    if (root == nullptr)
        return 0; // Base case: empty tree

    // Recursively transform left and right subtrees
    int leftSum = transformToSumTree(root->left);
    int rightSum = transformToSumTree(root->right);

    int oldValue = root->data;

    root->data = leftSum + rightSum; // Update current node's value to sum of left and right subtree sums

    return root->data + oldValue; // Return the sum including the old value
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, 7, -1, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    transformToSumTree(root);

    return 0;
}

/*
    Transform to Sum Tree:
    - A Sum Tree is a binary tree where each node's value is equal to the sum of the values of its left and right subtrees.
    - Leaf nodes are considered to have a value of 0 in the context of the sum tree.
    - The transformation is done in-place, meaning the original tree is modified to become a sum tree.

    Example:
            Original Tree:          Sum Tree:
                 10                     20
                /  \                   /  \
               -2   6                 4    0
              / \   \               / \    \
             8  -4   7             0  0    0
*/