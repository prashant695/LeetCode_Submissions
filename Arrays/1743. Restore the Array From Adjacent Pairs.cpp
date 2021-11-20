class Solution
{
public:
    map<int, int> vis;
    vector<int> res;
    void dfs(int x, unordered_map<int, vector<int>> &adj)
    {
        if (vis[x])
            return;
        vis[x] = 1;
        res.push_back(x);
        for (auto y : adj[x])
            dfs(y, adj);
    }
    vector<int> restoreArray(vector<vector<int>> &nums)
    {
        int x;
        map<int, int> m;
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i][0]]++, m[nums[i][1]]++;
        for (auto it : m)
            if (it.second == 1)
                x = it.first;

        for (int i = 0; i < nums.size(); i++)
        {
            adj[nums[i][0]].push_back(nums[i][1]);
            adj[nums[i][1]].push_back(nums[i][0]);
        }
        dfs(x, adj);
        return res;
    }
};