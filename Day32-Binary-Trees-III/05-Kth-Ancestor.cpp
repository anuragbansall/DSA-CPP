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

Node *findKthAncestor(Node *root, int &k, int target)
{
    if (root == nullptr)
        return nullptr; // Base case

    if (root->data == target)
        return root; // Target node found

    Node *leftAns = findKthAncestor(root->left, k, target);   // Search in left subtree
    Node *rightAns = findKthAncestor(root->right, k, target); // Search in right subtree

    if (leftAns != nullptr || rightAns != nullptr) // If target node is found in either subtree
    {
        if (k > 0) // Decrement k only if it's greater than 0
        {
            k--;

            if (k == 0) // If k reaches 0, current node is the Kth ancestor
            {
                k = -1; // To avoid further decrements
                return root;
            }
        }

        return leftAns ? leftAns : rightAns; // Return the non-null answer
    }

    return nullptr; // Target node not found in either subtree
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, 7, -1, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    int k = 2;
    int target = 7;

    Node *kthAncestor = findKthAncestor(root, k, target); // Output: 2
    cout << (kthAncestor ? kthAncestor->data : -1) << endl;
}

/*
    Kth Ancestor of a Node in Binary Tree:
    Given a binary tree and a node value, find the Kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.

    Example:
            1
          /   \
         2     3
        / \     \
       4   5     6
      /
     7

    K = 2, node = 7
    Output: 2

    Approach (Backtracking):
    1. We will perform a DFS traversal of the tree to find the target node.
    2. Once we find the target node, we will backtrack and decrement k at each ancestor node.
    3. When k reaches 0, we have found our Kth ancestor.
    4. If we reach the root and k is still greater than 0, it means the Kth ancestor does not exist.
*/