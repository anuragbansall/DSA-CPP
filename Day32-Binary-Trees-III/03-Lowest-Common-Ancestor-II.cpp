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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr; // Base case: if the tree is empty
    }

    if (root->data == n1 || root->data == n2)
    {
        return root; // If either n1 or n2 matches the root's data, return root
    }

    Node *leftLCA = LCA(root->left, n1, n2);   // Recur for left subtree
    Node *rightLCA = LCA(root->right, n1, n2); // Recur for right subtree

    if (leftLCA != nullptr && rightLCA != nullptr)
    {
        return root; // If both left and right subtrees return non-null, root is LCA
    }

    return (leftLCA != nullptr) ? leftLCA : rightLCA; // Otherwise return the non-null child
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    int n1 = 4, n2 = 5;
    Node *lcaNode = LCA(root, n1, n2);

    cout << "LCA of " << n1 << " and " << n2 << " is: " << (lcaNode ? lcaNode->data : -1) << endl;

    return 0;
}

/*
    Lowest Common Ancestor (LCA) in a Binary Tree:
    The Lowest Common Ancestor (LCA) of two nodes in a binary tree is defined as the deepest node that is an ancestor of both nodes.

    For example, in the following binary tree:

            1
           / \
          2   3
         / \   \
        4   5   6
    The LCA of nodes 4 and 5 is 2, as 2 is the deepest node that is an ancestor of both 4 and 5.
    The LCA of nodes 4 and 6 is 1, as 1 is the deepest node that is an ancestor of both 4 and 6.

    Approach:

*/