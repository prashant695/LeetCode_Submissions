class Solution
{
public:
    vector<vector<int>> res;
    void solve(vector<vector<int>> &graph, int curr_node, int end, vector<int> path)
    {
        path.push_back(curr_node);

        if (curr_node == end)
        {
            res.push_back(path);
            return;
        }

        for (auto x : graph[curr_node])
            solve(graph, x, end, path);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> path;
        solve(graph, 0, graph.size() - 1, path);
        return res;
    }
};