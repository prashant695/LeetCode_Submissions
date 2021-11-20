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
    TreeNode *tmp = NULL;
    void flatten(TreeNode *root)
    {
        if (!root || (!root->left and !root->right))
            return;

        if (root->left)
        {
            flatten(root->left);
            TreeNode *tmp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *p = root->right;
            while (p->right)
            {
                p = p->right;
            }
            p->right = tmp;
        }
        flatten(root->right);
    }
};