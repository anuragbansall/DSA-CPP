#include <iostream>
using namespace std;

int main(void)
{

    return 0;
}

/*
    Binary Search Tree (BST):
    - BST is a special type of binary tree.
    - In a BST, for each node:
        - The left subtree contains only nodes with values less than the node's value.
        - The right subtree contains only nodes with values greater than the node's value.
        - Both the left and right subtrees must also be binary search trees.
    - This property makes BSTs efficient for searching, inserting, and deleting elements.
    - Average time complexity for search, insert, and delete operations is O(log n).
    - Inorder traversal of a BST yields the nodes in sorted order.

    Example of a BST:
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \    /
         4   7  13

    In this example:
    - The left subtree of the root node (8) contains values less than 8 (3, 1, 6, 4, 7).
    - The right subtree contains values greater than 8 (10, 14, 13).
    - This structure allows for efficient searching, as you can eliminate half of the tree at each step.
*/