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
    int par_x, par_y, dep_x = -1, dep_y = -1;
    void dfs(TreeNode *root, int depth, int parent, int x, int y)
    {
        if (root)
        {
            if (root->val == x)
            {
                par_x = parent;
                dep_x = depth;
            }
            else if (root->val == y)
            {
                par_y = parent;
                dep_y = depth;
            }
            else if (dep_x != -1 and dep_y != -1)
                return;
            dfs(root->left, depth + 1, root->val, x, y);
            dfs(root->right, depth + 1, root->val, x, y);
        }
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        dfs(root, 0, -1, x, y);
        return dep_x == dep_y and par_x != par_y;
    }
};