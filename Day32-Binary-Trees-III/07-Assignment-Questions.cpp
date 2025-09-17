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

bool isUnivalTree(Node *root, int value)
{
    if (root == nullptr)
        return true;

    if (root->data != value)
        return false;

    return isUnivalTree(root->left, value) && isUnivalTree(root->right, value);
}

Node *invertTree(Node *root)
{
    if (root == nullptr)
        return nullptr;

    auto temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

Node *removeLeafNodes(Node *root, int target)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if (root->left == nullptr && root->right == nullptr && root->data == target)
    {
        delete root;
        return nullptr;
    }

    return root;
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, 7, -1, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    /*
        Question 1: A binary tree is called uni-valued if every node in the tree has the same value.
        Given the root of a binary tree, return true if the tree is uni-valued, otherwise return false.
    */

    if (isUnivalTree(root, root->data))
        cout << "The tree is uni-valued." << endl;
    else
        cout << "The tree is not uni-valued." << endl;

    /*
        Question 2: Given the root of a binary tree, invert the tree, and return its root.
    */

    root = invertTree(root);
    cout << "The tree has been inverted." << endl;

    /*
        Question 3: Given a binary tree root and an integer target, delete all the leaf nodes with value target.
        Note: After deleting a leaf node with value target, if its parent becomes a leaf node and has the value target, it should also be deleted.
        Continue this process until no such nodes remain.
    */

    int target = 5;
    root = removeLeafNodes(root, target);

    return 0;
}