/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int res = -1;
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int temp = (depth(root->left) + depth(root->right));
        res = max(res, temp);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return res;
    }
};