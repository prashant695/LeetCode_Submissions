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
    int ans = 0;
    int same(TreeNode *root, int val)
    {
        if (root)
        {
            if (root->val != val)
                return 0;
            return 1 + max(same(root->left, val), same(root->right, val));
        }
        return 0;
    }
    void dfs(TreeNode *root)
    {
        if (root)
        {
            ans = max((same(root->left, root->val) + same(root->right, root->val)), ans);
            dfs(root->left);
            dfs(root->right);
        }
    }
    int longestUnivaluePath(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};