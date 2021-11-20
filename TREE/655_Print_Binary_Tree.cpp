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
    void dfs(TreeNode *root, int row, int r, int col, int c, vector<vector<string>> &v)
    {
        if(root)
        {
            if(root->left) v[r+1][c-(pow(2,row-r-2))]=to_string(root->left->val);
            if(root->right) v[r+1][c+(pow(2,row-r-2))]=to_string(root->right->val);
            dfs(root->left,row,r+1,col,c-(pow(2,row-r-2)),v);
            dfs(root->right,row,r+1,col,c+(pow(2,row-r-2)),v);
        }
    }
    int depth(TreeNode* root)
    {
        if(root)
        return max(depth(root->left),depth(root->right))+1;
        return 0;
    }
    vector<vector<string>> printTree(TreeNode* root) {
         int h=depth(root),r=h,c=pow(2,r)-1;
         vector<vector<string>>v(r, vector<string>(c, ""));

         v[0][(c-1)/2]=to_string(root->val);
           dfs(root,r,0,c,(c-1)/2,v);
        return v;
    }
};