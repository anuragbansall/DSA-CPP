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

bool searchBST(Node *root, int target)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }
    else if (target < root->data)
    {
        return searchBST(root->left, target);
    }
    else
    {
        return searchBST(root->right, target);
    }
}

int main(void)
{
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node *root = buildBST(values);

    int target = 7;
    bool found = searchBST(root, target);

    cout << (found ? "Found" : "Not Found") << endl;

    return 0;
}