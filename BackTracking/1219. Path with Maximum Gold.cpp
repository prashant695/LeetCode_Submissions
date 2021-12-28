class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int r = grid.size();
        int c = grid[0].size();
        if (i < 0 or j < 0 or i >= r or j >= c or grid[i][j] == 0)
            return 0;

        int x = grid[i][j];
        grid[i][j] = 0;

        int ans = max({dfs(grid, i + 1, j),
                       dfs(grid, i, j + 1),
                       dfs(grid, i, j - 1),
                       dfs(grid, i - 1, j)});

        grid[i][j] = x;
        return x + ans;
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != 0)
                    res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};
