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
    long long prev = LONG_LONG_MAX;
    vector<int> v;
    int flg = 1;
    void in(TreeNode *root)
    {
        if (root)
        {
            in(root->left);
            if (prev != LONG_LONG_MAX)
            {
                if (root->val - prev <= 0)
                    flg = 0;
            }
            prev = root->val;
            in(root->right);
        }
    }
    bool isValidBST(TreeNode *root)
    {
        in(root);
        return flg;
    }
};