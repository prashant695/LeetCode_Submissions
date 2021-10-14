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
    TreeNode *root;
    void create(int x)
    {
        TreeNode *temp = root, *prev = root;
        while (temp)
        {
            prev = temp;
            if (x < temp->val)
                temp = temp->left;
            else
                temp = temp->right;
        }

        TreeNode *node = new TreeNode(x);
        if (x < prev->val)
            prev->left = node;
        else
            prev->right = node;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *t = new TreeNode(preorder[0]);
        root = t;
        for (int i = 1; i < preorder.size(); i++)
            create(preorder[i]);
        return root;
    }
};