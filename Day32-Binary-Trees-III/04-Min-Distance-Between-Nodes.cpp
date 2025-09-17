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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr; // Base case: if the tree is empty
    }

    if (root->data == n1 || root->data == n2)
    {
        return root; // If either n1 or n2 matches the root's data, return root
    }

    Node *leftLCA = LCA(root->left, n1, n2);   // Recur for left subtree
    Node *rightLCA = LCA(root->right, n1, n2); // Recur for right subtree

    if (leftLCA != nullptr && rightLCA != nullptr)
    {
        return root; // If both left and right subtrees return non-null, root is LCA
    }

    return (leftLCA != nullptr) ? leftLCA : rightLCA; // Otherwise return the non-null child
}

int findDistance(Node *root, int k)
{
    if (root == nullptr)
    {
        return -1; // Base case: if the tree is empty
    }

    if (root->data == k)
    {
        return 0; // If the current node matches k, return 0
    }

    // Recur for left and right subtrees
    int leftDistance = findDistance(root->left, k);
    int rightDistance = findDistance(root->right, k);

    if (leftDistance != -1)
    {
        return leftDistance + 1; // If found in left subtree, return the distance from left subtree
    }
    else if (rightDistance != -1)
    {
        return rightDistance + 1; // Otherwise, return the distance from right subtree
    }

    return -1; // If the node is not found in either subtree
}

int minDistance(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2); // Find the Lowest Common Ancestor (LCA) of n1 and n2

    if (lca == nullptr)
    {
        return -1; // If LCA is null, one or both nodes are not present in the tree
    }

    int d1 = findDistance(lca, n1); // Find distance from LCA to n1
    int d2 = findDistance(lca, n2); // Find distance from LCA to n2

    if (d1 == -1 || d2 == -1)
    {
        return -1; // If either node is not found, return -1
    }

    return d1 + d2; // Return the sum of distances from LCA to n1 and n2
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);
    int n1 = 4, n2 = 6;

    int distance = minDistance(root, n1, n2); // Output: 4
    cout << "Minimum distance between nodes " << n1 << " and " << n2 << " is: " << distance << endl;

    return 0;
}

/*
    Minimum Distance Between Two Nodes in a Binary Tree:
    Given a binary tree and two node values, find the minimum distance between the two nodes.
    The distance between two nodes is defined as the number of edges in the shortest path connecting them.
    If either of the nodes is not present in the tree, return -1.

    Example:
            1
          /   \
         2     3
        / \     \
       4   5     6

    Input: root = [1,2,3,4,5,null,6], n1 = 4, n2 = 5
    Output: 2

    Approach:
    1. Find the Lowest Common Ancestor (LCA) of the two nodes.
    2. Calculate the distance from the LCA to each of the nodes.
    3. The minimum distance will be the sum of the two distances.
    4. If either node is not found, return -1.
*/