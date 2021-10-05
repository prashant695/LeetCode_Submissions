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
    int sum = 0;
    void dfs(TreeNode *root)
    {
        if (root)
        {
            dfs(root->left);
            dfs(root->right);
            if (root->left && root->right)
                sum += abs(root->left->val - root->right->val);
            else if (root->right)
                sum += abs(root->right->val);
            else if (root->left)
                sum += abs(root->left->val);

            if (root->left)
                root->val += (root->left->val);
            if (root->right)
                root->val += (root->right->val);
        }
    }
    int findTilt(TreeNode *root)
    {
        dfs(root);
        return sum;
    }
};