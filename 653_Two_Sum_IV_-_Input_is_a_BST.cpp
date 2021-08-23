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
class Solution {
public:
    map<int,int>m;
    int ans=0;
    bool dfs(TreeNode* root, int k)
    {
        if(root)
        {
            if(m[k-root->val]) ans=1;
            else m[root->val]=1;
            dfs(root->left,k);
            dfs(root->right,k);
        }
        return 0;
    }
    bool findTarget(TreeNode* root, int k) {
        
        dfs(root,k);
        return ans;
    }
};