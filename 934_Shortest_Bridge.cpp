class Solution
{
public:
    vector<pair<int, int>> v, v2;
    int vis[101][101] = {0};
    void dfs(int flg, vector<vector<int>> &grid, int i, int j)
    {
        int r = grid.size(), c = grid[0].size();
        if (i >= r || i < 0 || j < 0 || j >= c)
            return;
        if (vis[i][j] == 1 || grid[i][j] == 0)
            return;

        vis[i][j] = 1;
        if (flg == 0)
            v.push_back({i, j});
        else
            v2.push_back({i, j});

        dfs(flg, grid, i + 1, j);
        dfs(flg, grid, i - 1, j);
        dfs(flg, grid, i, j + 1);
        dfs(flg, grid, i, j - 1);
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        int flg = 0, x, res = 200;
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == 1)
                {
                    dfs(flg, grid, i, j);
                    flg++;
                }
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v2.size(); j++)
            {
                x = abs(v[i].first - v2[j].first) + abs(v[i].second - v2[j].second);
                res = min(res, x);
            }
        }
        return res - 1;
    }
};