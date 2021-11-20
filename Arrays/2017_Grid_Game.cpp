class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        long long n = grid[0].size(), robob = LONG_LONG_MAX;
        long long pre[n];
        long long pre2[n];

        pre[0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
            pre[i] = pre[i - 1] + grid[0][i];

        pre2[0] = grid[1][0];
        for (int i = 1; i < grid[1].size(); i++)
            pre2[i] = pre2[i - 1] + grid[1][i];

        for (int i = 1; i < n - 1; i++)
        {
            robob = min(robob, max(pre[n - 1] - pre[i], pre2[i - 1]));
        }

        robob = min(robob, pre2[n - 2]);
        robob = min(robob, pre[n - 1] - pre[0]);
        return robob;
    }
};