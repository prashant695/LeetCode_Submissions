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

// Iterative Method_1
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        stack<Node *> q;
        vector<int> v;
        if (root == NULL)
            return v;
        q.push(root);
        while (q.empty() == false)
        {
            Node *t = q.top();
            q.pop();
            for (int i = t->children.size() - 1; i >= 0; i--)
                q.push(t->children[i]);
            v.push_back(t->val);
        }
        return v;
    }
};

// Recursive Method_2
class Solution
{
public:
    vector<int> v;
    vector<int> preorder(Node *root)
    {
        if (root == NULL)
            return {};
        v.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
        {
            preorder(root->children[i]);
        }
        return v;
    }
};