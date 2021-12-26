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
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size() + 1, -1);

        for (int i = 0; i < graph.size(); i++)
            if (color[i] == -1 and bfs(i, graph, color) == 0)
                return 0;

        return 1;
    }
};