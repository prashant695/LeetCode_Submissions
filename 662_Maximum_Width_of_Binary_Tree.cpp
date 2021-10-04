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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 1});
        long long ans = 1;
        while (q.empty() == false)
        {
            long long x = q.front().second;
            ans = max(ans, q.back().second - q.front().second + 1);
            int qu = q.size();
            for (int i = 0; i < qu; i++)
            {
                TreeNode *curr = q.front().first;
                long long idx = q.front().second - x;
                q.pop();
                if (curr->left)
                    q.push({curr->left, 2 * idx});
                if (curr->right)
                    q.push({curr->right, 2 * idx + 1});
            }
        }
        return ans;
    }
};