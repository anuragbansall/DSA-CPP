#include <iostream>
#include <map>
#include <queue>
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

void printTopView(Node *root)
{
    if (!root)
        return;

    queue<pair<Node *, int>> q; // Pair of node and its horizontal distance
    map<int, int> topViewMap;   // Map to store the top view nodes

    q.push({root, 0}); // Start with root at horizontal distance 0

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        Node *currentNode = front.first;
        int horizontalDistance = front.second;

        // If this horizontal distance is not already in the map, add it
        if (topViewMap.count(horizontalDistance) == 0)
        {
            topViewMap[horizontalDistance] = currentNode->data;
        }

        // Enqueue left and right children with updated horizontal distances
        if (currentNode->left)
            q.push({currentNode->left, horizontalDistance - 1});
        if (currentNode->right)
            q.push({currentNode->right, horizontalDistance + 1});
    }

    // Print the top view nodes in order of their horizontal distances
    for (const auto &entry : topViewMap)
    {
        cout << entry.second << " ";
    }

    cout << endl;
}

int main(void)
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 7, -1, -1};
    int index = 0;

    Node *root = buildTreeFromPreorder(preorder, index);

    printTopView(root);

    return 0;
}

/*
    Top View of Tree:
    1. The top view of a binary tree is the set of nodes visible when the tree is viewed from above.
    2. To determine the top view, we can perform a level-order traversal (BFS) while keeping track of the horizontal distance of each node from the root.
    3. We can use a map to store the first node encountered at each horizontal distance.
    4. The horizontal distance of the root is 0, the left child is -1, the right child is +1, and so on.
    5. After the traversal, the map will contain the top view nodes, which can be printed in order of their horizontal distances.
    6. The time complexity of this approach is O(n), where n is the number of nodes in the tree.
    7. The space complexity is O(w), where w is the maximum width of the tree (the maximum number of nodes at any level).

    Example:
            1
          /   \
         2     3
        / \   / \
       4   5 6   7

    Top View: 4 2 1 3 7
*/