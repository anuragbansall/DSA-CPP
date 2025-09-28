#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 0)
        return nullptr;

    int mid = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    vector<int> leftArr(nums.begin(), nums.begin() + mid);
    vector<int> rightArr(nums.begin() + mid + 1, nums.end());

    root->left = sortedArrayToBST(leftArr);
    root->right = sortedArrayToBST(rightArr);

    return root;
}

void inorderTraversal(TreeNode *root, vector<int> &nums)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left, nums);
    nums.push_back(root->val);
    inorderTraversal(root->right, nums);
}

TreeNode *balanceBST(TreeNode *root)
{
    vector<int> nums;
    inorderTraversal(root, nums);

    return sortedArrayToBST(nums);
}

int main(void)
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = sortedArrayToBST(nums);

    root = balanceBST(root);
    cout << "Root Value: " << root->val << endl; // Output: Root Value: 0

    return 0;
}