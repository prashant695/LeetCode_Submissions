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


// How To Proceed
// For every node present at a certain level, assume the node to be at
// level 0 i.e assume the node to be root node. Now the problem become similar
// to that of Path Sum I
class Solution
{
public:
    int res = 0;
    void path(TreeNode *root, int targetSum)
    {
        if (root)
        {
            if (root->val == targetSum)
                res++;
            path(root->left, targetSum - root->val);
            path(root->right, targetSum - root->val);
        }
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root)
        {
            path(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return res;
    }
};
