class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int dp[1691];
        dp[1] = 1;
        int x2 = 1, x3 = 1, x5 = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[x2] * 2, min(dp[x3] * 3, dp[x5] * 5));
            if (dp[i] == dp[x2] * 2)
                x2++;
            if (dp[i] == dp[x3] * 3)
                x3++;
            if (dp[i] == dp[x5] * 5)
                x5++;
        }
        return dp[n];
    }
};
