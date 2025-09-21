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

Node *findInorderSuccessor(Node *node)
{
    Node *current = node->right;

    while (current && current->left != nullptr)
    {
        current = current->left;
    }

    return current;
}

Node *findInorderPredecessor(Node *node)
{
    Node *current = node->left;

    while (current && current->right != nullptr)
    {
        current = current->right;
    }

    return current;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return nullptr; // Base case: If the tree is empty

    if (key < root->data) // Key is in the left subtree
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) // Key is in the right subtree
    {
        root->right = deleteNode(root->right, key);
    }
    else // Found the node to be deleted
    {
        // Case 1: Node with only one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        // Using inorder successor
        Node *successor = findInorderSuccessor(root);
        root->data = successor->data;                           // Copy the inorder successor's value to this node
        root->right = deleteNode(root->right, successor->data); // Delete the inorder successor
    }

    return root; // Return the (possibly updated) root pointer
}

int main(void)
{
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node *root = buildBST(values);

    int key = 8;
    root = deleteNode(root, key);

    cout << "Node with key " << key << " deleted from the BST." << endl;
    cout << "New root after deletion: " << root->data << endl;

    return 0;
}

/*
    Delete a Node in a BST:
    - If the node is a leaf node, simply remove it.
    - If the node has one child, replace the node with its child.
    - If the node has two children, find the inorder successor (smallest in the right subtree) or inorder predecessor (largest in the left subtree), copy its value to the current node, and delete the successor/predecessor.
    - Return the (possibly updated) root of the tree.

    Inorder Successor:
    - The inorder successor of a node is the node with the smallest value in its right subtree.
    - To find the inorder successor, go to the right child of the node and then keep going to the left child until you reach a node with no left child.
    - Replace the value of the node to be deleted with the value of the inorder successor.
    - Delete the inorder successor node from the right subtree.

    Inorder Predecessor:
    - The inorder predecessor of a node is the node with the largest value in its left subtree.
    - To find the inorder predecessor, go to the left child of the node and then keep going to the right child until you reach a node with no right child.
    - Replace the value of the node to be deleted with the value of the inorder predecessor.
    - Delete the inorder predecessor node from the left subtree.

    Note: The inorder successor and predecessor always have at most one child, making their deletion straightforward.

    Time Complexity: O(h), where h is the height of the tree.
    Space Complexity: O(h) due to recursion stack.
*/