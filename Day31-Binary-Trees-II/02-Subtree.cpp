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

bool isIdentical(Node *root, Node *subRoot)
{
    if (root == nullptr && subRoot == nullptr)
        return true;

    if (root == nullptr || subRoot == nullptr)
        return false;

    if (root->data != subRoot->data)
        return false;

    return isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
}

bool isSubtree(Node *root, Node *subRoot)
{

    if (root == nullptr)
        return false; // An empty tree cannot have a non-empty subtree

    if (isIdentical(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);
    Node *subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    if (isSubtree(root, subRoot))
        cout << "Subtree exists" << endl;
    else
        cout << "Subtree does not exist" << endl;

    return 0;
}

/*
    Subtree of another tree:
    Return true if there is a subtree of root with the same structure and node values as subRoot and false otherwise.

    Example :
        Root
            1
          /   \
         2     3
        / \     \
       4   5     6

    SubRoot
            2
          /   \
         4     5

    Output: true (because there is a subtree of root with the same structure and node values as subRoot)

    Approach:
    1. If the main tree is empty, return false.
   2. If the subtree is empty, return true.
   3. If the values of the current nodes of both trees are different, return false.
   4. Recursively check the left and right subtrees.
    5. If both left and right subtree checks return true, return true; otherwise, return false.
*/