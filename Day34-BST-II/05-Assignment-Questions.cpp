#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
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

void rangeSumBST(Node *root, int low, int high, int &sum)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->data >= low && root->data <= high)
    {
        sum += root->data;
    }

    if (root->data > low)
    {
        rangeSumBST(root->left, low, high, sum);
    }

    if (root->data < high)
    {
        rangeSumBST(root->right, low, high, sum);
    }
}

int minDiffInBST(Node *root, int K)
{
    int minDiff = INT_MAX;
    int closestValue = -1; // Assuming all node values are non-negative

    while (root != nullptr)
    {
        int currentDiff = abs(root->data - K);

        if (currentDiff < minDiff)
        {
            minDiff = currentDiff;
            closestValue = root->data;
        }

        if (K < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return closestValue;
}

void kthSmallestUtil(Node *root, int k, int &count, int &result)
{
    if (root == nullptr || result != -1)
    {
        return;
    }

    kthSmallestUtil(root->left, k, count, result);

    count++;
    if (count == k)
    {
        result = root->data;
        return;
    }

    kthSmallestUtil(root->right, k, count, result);
}

void inorderTraversal(Node *root, set<int> &values)
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left, values);
    values.insert(root->data);
    inorderTraversal(root->right, values);
}

bool findComplement(Node *root, set<int> &values, int target)
{
    if (root == nullptr)
        return false;

    if (values.find(target - root->data) != values.end())
        return true;

    return findComplement(root->left, values, target) || findComplement(root->right, values, target);
}

bool twoSumBSTs(Node *root1, Node *root2, int target)
{
    set<int> values;

    inorderTraversal(root1, values);
    return findComplement(root2, values, target);
}

struct BSTInfo
{
    bool isBST;
    int minVal;
    int maxVal;
    int sum;

    BSTInfo(bool bst, int minV, int maxV, int s) : isBST(bst), minVal(minV), maxVal(maxV), sum(s) {}
};

BSTInfo maxSumBSTUtil(Node *root, int &maxSum)
{
    if (root == nullptr)
    {
        return BSTInfo(true, INT_MAX, INT_MIN, 0);
    }

    BSTInfo leftInfo = maxSumBSTUtil(root->left, maxSum);
    BSTInfo rightInfo = maxSumBSTUtil(root->right, maxSum);

    if (leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.maxVal && root->data < rightInfo.minVal)
    {
        int currentSum = leftInfo.sum + rightInfo.sum + root->data;
        maxSum = max(maxSum, currentSum);

        return BSTInfo(true, min(root->data, leftInfo.minVal), max(root->data, rightInfo.maxVal), currentSum);
    }
    else
    {
        return BSTInfo(false, 0, 0, 0);
    }
}

int main(void)
{
    /*
        Question 1 : Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
    */
    vector<int> values = {10, 5, 15, 3, 7, 18};
    Node *root = buildBST(values);
    int low = 7, high = 15;
    int sum = 0;

    rangeSumBST(root, low, high, sum);
    cout << "Range Sum BST: " << sum << endl;

    /*
        Question 2:
        Given a binary search tree and a target value K, find the node value in the BST
        that has the minimum absolute difference with K.

        Example BST:
                8
               / \
              5  11
             / \   \
            3   6  20

        Input 1: K = 5
        Output 1: ans = 5 (abs diff = 0)

        Input 2: K = 19
        Output 2: ans = 20 (abs diff = 1)
    */
    vector<int> values2 = {8, 5, 11, 3, 6, 20};
    Node *root2 = buildBST(values2);
    int K = 19;

    int closestValue = minDiffInBST(root2, K);
    cout << "Closest Value to " << K << " in BST: " << closestValue << endl;

    /*
        Question 3 : Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
    */
    vector<int> values3 = {3, 1, 4, 2};
    Node *root3 = buildBST(values3);
    int k = 1;
    int count = 0;
    int result = -1;

    kthSmallestUtil(root3, k, count, result);
    cout << k << "th Smallest Element in BST: " << result << endl;

    /*
        Question 4 : Given two binary search trees, return True if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.
    */
    vector<int> values4_1 = {2, 1, 4};
    vector<int> values4_2 = {1, 0, 3};
    Node *root4_1 = buildBST(values4_1);
    Node *root4_2 = buildBST(values4_2);

    int target = 5;
    bool result4 = twoSumBSTs(root4_1, root4_2, target);
    cout << "Two Sum BSTs (Target = " << target << "): " << (result4 ? "True" : "False") << endl;

    /*
        Question 5 : Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

        Assume a BST is defined as follows:
        ● The left subtree of a node contains only nodes with keys less than the node's
        key.
        ● The right subtree of a node contains only nodes with keys greater than the
        node's key.
        ● Both the left and right subtrees must also be binary search trees.
    */

    vector<int> values5 = {1, 4, 3, 2, 5, 4, 6};
    Node *root5 = buildBST(values5);
    int maxSum = 0;

    maxSumBSTUtil(root5, maxSum);
    cout << "Maximum Sum BST in Binary Tree: " << maxSum << endl;

    return 0;
}