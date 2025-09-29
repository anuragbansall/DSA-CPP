#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
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

void inorderTraversal(Node *root, vector<int> &values)
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left, values);
    values.push_back(root->data);
    inorderTraversal(root->right, values);
}

void mergeSortedArrays(const vector<int> &arr1, const vector<int> &arr2, vector<int> &merged)
{
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            merged.push_back(arr1[i]);
            i++;
        }
        else
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size())
    {
        merged.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {
        merged.push_back(arr2[j]);
        j++;
    }
}

Node *buildBSTFromSortedArray(const vector<int> &values, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    Node *node = new Node(values[mid]);

    node->left = buildBSTFromSortedArray(values, start, mid - 1);
    node->right = buildBSTFromSortedArray(values, mid + 1, end);

    return node;
}

Node *mergeBSTs(Node *root1, Node *root2)
{
    vector<int> nodes1, nodes2;

    inorderTraversal(root1, nodes1);
    inorderTraversal(root2, nodes2);

    vector<int> mergedNodes;
    mergeSortedArrays(nodes1, nodes2, mergedNodes);

    return buildBSTFromSortedArray(mergedNodes, 0, mergedNodes.size() - 1);
}

int main(void)
{
    vector<int> values = {10, 5, 1, 8, 15, 7, 20};
    Node *root = buildBST(values);

    vector<int> values2 = {12, 6, 3, 9, 18, 4, 25};
    Node *root2 = buildBST(values2);

    Node *mergedRoot = mergeBSTs(root, root2);

    return 0;
}