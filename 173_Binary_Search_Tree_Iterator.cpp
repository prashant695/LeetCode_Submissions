// Method-1
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
class BSTIterator
{
public:
    vector<int> v;
    int i = 0;
    void dfs(TreeNode *root)
    {
        if (root)
        {
            dfs(root->left);
            v.push_back(root->val);
            dfs(root->right);
        }
    }
    BSTIterator(TreeNode *root)
    {
        dfs(root);
    }

    int next()
    {
        return v[i++];
    }

    bool hasNext()
    {
        return i < v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// Method-2
class BSTIterator
{
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root)
    {
        push(root);
    }

    int next()
    {
        TreeNode *t = s.top();
        s.pop();
        push(t->right);
        return t->val;
    }

    bool hasNext()
    {
        return s.empty() == false;
    }

    void push(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
};
