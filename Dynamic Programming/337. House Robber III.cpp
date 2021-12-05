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
    unordered_map<TreeNode *, int> m;
    int rob(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (m[root])
            return m[root];
        int x = root->val;
        if (root->left)
            x += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            x += rob(root->right->left) + rob(root->right->right);

        return m[root] = max(x, rob(root->left) + rob(root->right));
    }
};