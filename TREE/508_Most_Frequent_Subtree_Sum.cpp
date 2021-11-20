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
    map<int, int> m;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        dfs(root->right);
        if (root->left)
            root->val += root->left->val;
        if (root->right)
            root->val += root->right->val;

        m[root->val]++;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> v;
        dfs(root);
        int maxx = -1;
        for (auto it : m)
        {
            if (it.second > maxx)
                maxx = it.second;
        }
        for (auto it : m)
        {
            if (it.second == maxx)
                v.push_back(it.first);
        }
        return v;
    }
};