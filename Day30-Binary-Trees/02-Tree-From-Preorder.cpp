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

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    return 0;
}

/*
    Preorder Sequence:
    - Preorder sequence is made by visiting the root node first, then recursively visiting the left subtree, followed by the right subtree.
    - If the node is null, we represent it with a special marker (e.g., -1). This helps in identifying the structure of the tree during reconstruction.
    - Example: For the tree:
          1
         / \
        2   3
       / \
      4   5
      The preorder sequence would be: [1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1]
*/