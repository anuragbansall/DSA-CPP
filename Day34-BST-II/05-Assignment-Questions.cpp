#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
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

void rangeSumBST(Node *root, int low, int high, int &sum)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->data >= low && root->data <= high)
    {
        sum += root->data;
    }

    if (root->data > low)
    {
        rangeSumBST(root->left, low, high, sum);
    }

    if (root->data < high)
    {
        rangeSumBST(root->right, low, high, sum);
    }
}

int main(void)
{
    /*
        Question 1 : Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
    */
    vector<int> values = {10, 5, 15, 3, 7, 18};
    Node *root = buildBST(values);
    int low = 7, high = 15;
    int sum = 0;

    rangeSumBST(root, low, high, sum);
    cout << "Range Sum BST: " << sum << endl;

    return 0;
}