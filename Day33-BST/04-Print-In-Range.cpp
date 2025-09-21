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

void printInRange(Node *root, int low, int high)
{
    if (root == nullptr)
        return;

    if (root->data > low)
        printInRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        cout << root->data << " ";

    if (root->data < high)
        printInRange(root->right, low, high);

    return;
}

int main(void)
{
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node *root = buildBST(values);

    int k1 = 5, k2 = 12;
    cout << "Elements in range [" << k1 << ", " << k2 << "]: ";
    printInRange(root, k1, k2);

    return 0;
}

/*
    Print in Range
    - Given a BST and a range [k1, k2], print all elements in the range in increasing order.
    - Example:
        - Input: [8, 3, 10, 1, 6, 14, 4, 7, 13], k1 = 5, k2 = 12
        - Output: 6 7 8 10

    Approach:
    - Perform an in-order traversal of the BST.
    - During the traversal, check if the current node's value lies within the range [k1, k2].
    - If it does, print the value.
    - If the current node's value is greater than k1, recursively traverse the left subtree.
    - If the current node's value is less than k2, recursively traverse the right subtree.

    Time Complexity: O(n) in the worst case, where n is the number of nodes in the BST.
    Space Complexity: O(h) for the recursion stack, where h is the height of the BST.
*/