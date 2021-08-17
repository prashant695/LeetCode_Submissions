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
    int cnt = 0;
    int pre(TreeNode *root, int ma)
    {
        if (root != NULL)
        {
            if (root->val >= ma)
                cnt++;
            pre(root->left, max(ma, root->val));
            pre(root->right, max(ma, root->val));
        }
        return 0;
    }
    int goodNodes(TreeNode *root)
    {
        pre(root, root->val);
        return cnt;
    }
};