class Solution
{
public:
    vector<vector<int>> adj;
    vector<int> vis;
    void dfs(int node)
    {
        if (vis[node] == 1)
            return;
        vis[node] = 1;
        for (auto it : adj[node])
            dfs(it);
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int cnt = 0;
        for (int i = 0; i <= 200; i++)
            vis.push_back(0);
        adj.resize(201);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] && i != j)
                {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
                cnt += 1;
            }
        }
        return cnt;
    }
};