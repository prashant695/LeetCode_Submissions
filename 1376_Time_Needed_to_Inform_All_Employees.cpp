class Solution
{
public:
    int ans = -1;
    void dfs(int headID, vector<int> &informTime, int curr, vector<vector<int>> &adj)
    {
        for (auto x : adj[headID])
        {
            ans = max(ans, informTime[x] + curr);
            dfs(x, informTime, informTime[x] + curr, adj);
        }
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < manager.size(); i++)
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        dfs(headID, informTime, informTime[headID], adj);
        if (ans == -1)
            return 0;
        return ans;
    }
};