#include <iostream>
#include <vector>
#include <queue>
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

void levelorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }

    cout << endl;
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    cout << "Level Order Traversal: ";
    levelorderTraversal(root);

    return 0;
}

/*
    Level Order Traversal:
    - Use a queue to facilitate the breadth-first traversal of the tree.
    - Start by enqueuing the root node.
    - While the queue is not empty:
        - Dequeue a node from the front of the queue and process it (e.g., print its value).
        - Enqueue the left child of the dequeued node if it exists.
        - Enqueue the right child of the dequeued node if it exists.

    Example:
        For the binary tree:
                1
               / \
              2   3
             / \
            4   5

        The level order traversal is: 1, 2, 3, 4, 5
*/