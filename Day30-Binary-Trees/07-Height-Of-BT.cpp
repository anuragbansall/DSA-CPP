#include <iostream>
#include <vector>
#include <queue>
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

int heightOfBT(Node *root)
{
    if (root == nullptr)
        return 0; // Height of empty tree is 0

    int leftHeight = heightOfBT(root->left);
    int rightHeight = heightOfBT(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    cout << "Height of the Binary Tree: ";
    cout << heightOfBT(root) << endl;

    return 0;
}

/*
    Height of a Binary Tree:
    - The height of a binary tree is the number of edges on the longest path from the root node to a leaf node.
    - An empty tree has a height of 0.
    - A tree with only one node (the root) has a height of 1.
    - The height can be calculated recursively by finding the maximum height of the left and right subtrees and adding 1 for the root node.
    - Time Complexity: O(n), where n is the number of nodes in the tree (each node is visited once).
    - Space Complexity: O(h), where h is the height of the tree (due to recursion stack).

    Example:
            1
           / \
          2   3
         / \
        4   5
    Height = 3 (Nodes 1 -> 2 -> 4 or 1 -> 2 -> 5)
*/