class Solution
{
public:
    bool bfs(int node, vector<vector<int>> &adj, vector<int> &color)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;

        while (q.empty() == false)
        {
            int current = q.front();
            q.pop();

            for (auto x : adj[current])
            {
                if (color[x] == color[current])
                    return 0;
                if (color[x] == -1)
                    color[x] = 1 - color[current], q.push(x);
            }
        }
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> adj(n + 1);
        vector<int> color(n + 1, -1);

        for (int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for (int i = 1; i <= n; i++)
            if (color[i] == -1 and bfs(i, adj, color) == 0)
                return 0;

        return 1;
    }
};