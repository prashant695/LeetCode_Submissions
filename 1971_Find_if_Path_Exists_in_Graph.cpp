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
    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {
        for (int i = 0; i < n; i++)
            vis.push_back(0);
        adj.resize(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(start);
        return vis[end] == 1;
    }
};