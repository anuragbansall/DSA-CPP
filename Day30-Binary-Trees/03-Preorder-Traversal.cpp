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
        left = right = nullptr;
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

void preorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    cout << "Preorder Traversal: ";
    preorderTraversal(root);

    return 0;
}

/*
    Preorder Traversal:
    - Preorder traversal is a method of visiting all the nodes in a binary tree where the root node is visited first, followed by the left subtree, and then the right subtree.
    - The traversal can be implemented using recursion or an iterative approach with a stack.
    - Example: For the tree:
          1
         / \
        2   3
       / \
      4   5
      The preorder traversal would visit the nodes in the order: 1, 2, 4, 5, 3
*/