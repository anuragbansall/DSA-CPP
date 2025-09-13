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

void postorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    cout << "Inorder Traversal: ";
    postorderTraversal(root);

    return 0;
}

/*
    Postorder Traversal:
    - Postorder traversal is a method of visiting all the nodes in a binary tree where the left subtree is visited first, followed by the right subtree, and finally the root node.
    - The traversal can be implemented using recursion or an iterative approach with two stacks.

    - Example: For the tree:
          1
         / \
        2   3
       / \
      4   5
      The postorder traversal would visit the nodes in the order: 4, 5, 2, 3, 1
*/