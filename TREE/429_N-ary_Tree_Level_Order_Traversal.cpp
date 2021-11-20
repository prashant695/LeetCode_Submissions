/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        queue<Node *> q;
        vector<int> v;
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        q.push(root);
        while (q.empty() == false)
        {
            int qu = q.size();
            vector<int> v;
            for (int i = 0; i < qu; i++)
            {
                Node *t = q.front();
                q.pop();
                v.push_back(t->val);
                for (int i = 0; i < t->children.size(); i++)
                    q.push(t->children[i]);
            }
            res.push_back(v);
        }
        return res;
    }
};
