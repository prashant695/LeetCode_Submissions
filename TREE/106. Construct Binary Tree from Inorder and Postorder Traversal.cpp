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
    int idx;
    map<int, int> m;
    TreeNode *create(vector<int> &pos, vector<int> &in, int i, int j)
    {
        if (i > j)
            return NULL;
        TreeNode *t = new TreeNode(pos[idx--]);
        t->right = create(pos, in, m[t->val] + 1, j);
        t->left = create(pos, in, i, m[t->val] - 1);
        return t;
    }
    TreeNode *buildTree(vector<int> &in, vector<int> &pos)
    {
        idx = in.size() - 1;
        for (int i = 0; i < in.size(); i++)
            m[in[i]] = i;
        TreeNode *root = create(pos, in, 0, in.size() - 1);
        return root;
    }
};