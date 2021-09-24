/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> v;
    map<TreeNode *, TreeNode *> parent;
    map<TreeNode *, int> vis;
    void bfs(TreeNode *target, int k)
    {
        if (target && k >= 0 && vis[target] == 0)
        {
            vis[target] = 1;
            if (k == 0)
                v.push_back(target->val);
            bfs(parent[target], k - 1);
            bfs(target->left, k - 1);
            bfs(target->right, k - 1);
        }
    }
    void dfs(TreeNode *root)
    {
        if (root)
        {
            if (root->left)
                parent[root->left] = root;
            if (root->right)
                parent[root->right] = root;
            dfs(root->left);
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        dfs(root);
        bfs(target, k);
        return v;
    }
};