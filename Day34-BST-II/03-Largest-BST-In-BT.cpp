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

vector<int> largestBSTinBT(Node *root)
{
    if (root == nullptr)
    {
        return {0, INT_MAX, INT_MIN}; // size, min, max
    }

    vector<int> left = largestBSTinBT(root->left);
    vector<int> right = largestBSTinBT(root->right);

    if (left[0] == -1 || right[0] == -1 || root->data <= left[2] || root->data >= right[1])
    {
        return {-1, 0, 0}; // Not a BST
    }

    // It's a BST
    int size = left[0] + right[0] + 1;
    int minVal = min(left[1], root->data);
    int maxVal = max(right[2], root->data);

    return {size, minVal, maxVal};
}

int main(void)
{
    vector<int> values = {10, 5, 1, 8, 15, 7, 20};
    Node *root = buildBST(values);

    vector<int> result = largestBSTinBT(root);
    cout << "Size of largest BST: " << result[0] << endl;
    cout << "Min value in largest BST: " << result[1] << endl;
    cout << "Max value in largest BST: " << result[2] << endl;

    return 0;
}