#include <iostream>
#include <vector>
#include <climits>
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

bool isValidBST(Node *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == nullptr)
        return true;

    if (root->data < min || root->data > max)
        return false;

    return isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max);
}

int main(void)
{
    vector<int> values = {8, 30, 10, 1, 6, 14, 4, 7, 13};
    Node *root = buildBST(values);

    if (isValidBST(root))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is NOT a valid BST." << endl;

    return 0;
}