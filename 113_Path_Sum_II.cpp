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
    int res = 0;
    vector<vector<int>> v;
    int soln(TreeNode *root, int num, vector<int> v2, int t)
    {
        if (root)
        {
            v2.push_back(root->val);
            num += root->val;
            if (root->left == NULL && root->right == NULL)
                if (num == t)
                    v.push_back(v2);
            soln(root->left, num, v2, t);
            soln(root->right, num, v2, t);
        }
        return res;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> v2;
        soln(root, 0, v2, targetSum);
        return v;
    }
};
