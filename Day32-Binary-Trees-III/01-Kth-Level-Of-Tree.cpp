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

void printKthLevel(Node *root, int k)
{
    if (root == nullptr) // base case
        return;

    if (k == 0) // base case
    {
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, k - 1);  // go to next level
    printKthLevel(root->right, k - 1); // go to next level
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    int k = 2; // Change this value to test different levels
    cout << "Nodes at level " << k << ": ";
    printKthLevel(root, k);
    cout << endl;

    return 0;
}