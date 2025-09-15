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

int diameterOfTree(Node *root, int &maxDiameter)
{
    if (root == nullptr)
        return 0;

    int leftHeight = diameterOfTree(root->left, maxDiameter);
    int rightHeight = diameterOfTree(root->right, maxDiameter);

    maxDiameter = max(maxDiameter, leftHeight + rightHeight + 1);

    return max(leftHeight, rightHeight) + 1;
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, 6, -1, -1, -1, 5, -1, -1, 3, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    int maxDiameter = 0;
    cout << "Height of the tree: " << diameterOfTree(root, maxDiameter) << endl; // Output: 4

    cout << "Diameter of the tree: " << maxDiameter << endl; // Output: 5

    return 0;
}

/*
    Diameter of a tree is the longest path between any two nodes in a tree.
    The length of path is represented by the number of nodes on the path.
    The path may or may not pass through the root.

    Example:
            1
          /   \
         2     3
        / \
       4   5
      /
     6
    The diameter of the above tree is 5 (6 -> 4 -> 2 -> 1 -> 3)

    Approach:
    1. We can find the diameter of a tree by finding the height of each subtree
       and keeping track of the maximum height found so far.
    2. The diameter at any node is the sum of the heights of its left and right subtrees.
    3. We can use a recursive function to calculate the height of each subtree and
       update the maximum diameter found so far.
    4. The time complexity of this approach is O(n), where n is the number of nodes in the tree.
    5. The space complexity is O(h), where h is the height of the tree
*/