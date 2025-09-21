#include <iostream>
#include <vector>
#include <string>
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

void printRootToLeafPaths(Node *root, string path)
{
    if (root == nullptr)
        return;

    path += to_string(root->data);

    if (root->left == nullptr && root->right == nullptr) // leaf node
    {
        cout << path << endl;
    }

    path += "->";

    printRootToLeafPaths(root->left, path);
    printRootToLeafPaths(root->right, path);
}

int main(void)
{
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node *root = buildBST(values);

    cout << "Root to Leaf Paths in the BST:" << endl;
    printRootToLeafPaths(root, "");

    return 0;
}