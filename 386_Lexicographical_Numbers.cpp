class Solution
{
public:
    void dfs(vector<int> &res, int n, int curr)
    {
        if (curr > n)
            return;
        res.push_back(curr);
        dfs(res, n, curr * 10);
        if (curr % 10 != 9)
            dfs(res, n, curr + 1);
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        dfs(res, n, 1);
        return res;
    }
};
