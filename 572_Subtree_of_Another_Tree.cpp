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
    bool flg=0;
    bool same(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL) return true;
        else if(root==NULL && subRoot!=NULL) return false;
        else if(root!=NULL && subRoot==NULL) return false;
        if(root->val!=subRoot->val) return false;
         return same(root->left,subRoot->left) && same(root->right,subRoot->right);
        
        return true;
       
    }
    bool dfs(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL) return true;
        else if(root==NULL && subRoot!=NULL) return false;
        else if(root!=NULL && subRoot==NULL) return false;
        else if(root->val == subRoot->val)
            if(same(root,subRoot)) flg=1;
        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
        
        return true;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root,subRoot);
        return flg==1;
    }
};