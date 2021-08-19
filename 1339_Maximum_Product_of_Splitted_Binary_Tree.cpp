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
    long long ans = -1, mod = 1000000007;
    int dfs2(TreeNode *root, long long k)
    {
        if (root)
        {
            long long a = root->val;
            long long b = k - a;
            long long c = a * b;
            ans = max(ans, c);
            dfs2(root->left, k);
            dfs2(root->right, k);
        }
        return 0;
    }
    int dfs(TreeNode *root)
    {
        if (root)
        {
            dfs(root->left);
            dfs(root->right);
            if (root->left)
                root->val += root->left->val;
            if (root->right)
                root->val += root->right->val;
        }
        return 0;
    }
    long long maxProduct(TreeNode *root)
    {
        dfs(root);
        dfs2(root, root->val);
        return ans % mod;
    }
};