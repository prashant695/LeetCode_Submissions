// Method - 1
class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> res;
        int indegree[n];
        for (int i = 0; i < n; i++)
            indegree[i] = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            indegree[edges[i][1]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

// Method - 2
class Solution
{
public:
    int vis[100006];
    void dfs(int i, vector<vector<int>> &adj)
    {
        if (vis[i])
            return;
        vis[i] = 1;
        for (auto x : adj[i])
            dfs(x, adj);
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        for (int i = 0; i < n; i++)
            vis[i] = 0;
        vector<int> res;
        vector<vector<int>> adj(n + 1);
        int indegree[n];
        for (int i = 0; i < n; i++)
            indegree[i] = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            indegree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && indegree[i] == 0)
            {
                res.push_back(i);
                dfs(i, adj);
            }
        }
        return res;
    }
};