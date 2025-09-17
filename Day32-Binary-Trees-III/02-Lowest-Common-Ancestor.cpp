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

// Find Path from root to the given node
bool findPath(Node *root, vector<int> &path, int k)
{ // k is the node value
    if (root == nullptr)
        return false;

    path.push_back(root->data);

    if (root->data == k)
        return true;

    if (findPath(root->left, path, k) || findPath(root->right, path, k))
        return true;

    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;

    findPath(root, path1, n1);
    findPath(root, path2, n2);

    int lca = -1;
    int i = 0, j = 0;

    while (i < path1.size() && j < path2.size())
    {
        if (path1[i] == path2[j])
            lca = path1[i];

        i++;
        j++;
    }

    return lca;
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    int n1 = 4, n2 = 6;

    cout << "LCA of " << n1 << " and " << n2 << " is: " << LCA(root, n1, n2) << endl;

    return 0;
}

/*
    Lowest Common Ancestor (LCA) in a Binary Tree:
    The Lowest Common Ancestor (LCA) of two nodes in a binary tree is defined as the deepest node that is an ancestor of both nodes.

    For example, in the following binary tree:

            1
           / \
          2   3
         / \   \
        4   5   6
    The LCA of nodes 4 and 5 is 2, as 2 is the deepest node that is an ancestor of both 4 and 5.
    The LCA of nodes 4 and 6 is 1, as 1 is the deepest node that is an ancestor of both 4 and 6.

    Approach:
    1. Find the path from the root to each of the two nodes.
    2. Compare the paths to find the last common node.
    3. The last common node in the paths is the LCA.

    Time Complexity: O(N) where N is the number of nodes in the binary tree.
    Space Complexity: O(H) where H is the height of the binary tree (for storing the paths).

    Note: This approach assumes that both nodes are present in the binary tree.
*/