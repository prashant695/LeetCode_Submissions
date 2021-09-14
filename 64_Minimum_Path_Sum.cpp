class Solution
{
public:
    int dp[201][201];
    int help(int down, int right, vector<vector<int>> &grid)
    {
        if (dp[down][right] != -1)
            return dp[down][right];
        int r = grid.size();
        int c = grid[0].size();
        if (down == r - 1 && right == c - 1)
            return grid[down][right];
        if (down == r - 1)
            return grid[down][right] + help(down, right + 1, grid);
        if (right == c - 1)
            return grid[down][right] + help(down + 1, right, grid);
        return dp[down][right] = min(help(down + 1, right, grid), help(down, right + 1, grid)) + grid[down][right];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        return help(0, 0, grid);
    }
};
