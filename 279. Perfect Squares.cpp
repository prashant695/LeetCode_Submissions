class Solution
{
public:
    int numSquares(int n)
    {
        int dp[n + 1], minn;
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            minn = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                if (dp[i - (j * j)] < minn)
                    minn = dp[i - (j * j)];
            }
            dp[i] = minn + 1;
        }
        return dp[n];
    }
};