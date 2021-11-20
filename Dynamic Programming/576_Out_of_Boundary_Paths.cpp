class Solution
{
public:
    int dp[51][51][51];
    int help(int m, int n, int startRow, int startColumn, int maxMove, int currMov)
    {
        if ((startRow == m || startColumn == n || startRow == -1 || startColumn == -1) && (currMov <= maxMove))
            return 1;
        if (currMov > maxMove)
            return 0;
        if (dp[startRow][startColumn][currMov] != -1)
            return dp[startRow][startColumn][currMov];
        long long x = 0;
        x = x + help(m, n, startRow + 1, startColumn, maxMove, currMov + 1) % 1000000007;
        x = x + help(m, n, startRow - 1, startColumn, maxMove, currMov + 1) % 1000000007;
        x = x + help(m, n, startRow, startColumn + 1, maxMove, currMov + 1) % 1000000007;
        x = x + help(m, n, startRow, startColumn - 1, maxMove, currMov + 1) % 1000000007;
        return dp[startRow][startColumn][currMov] = x % 1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return help(m, n, startRow, startColumn, maxMove, 0);
    }
};