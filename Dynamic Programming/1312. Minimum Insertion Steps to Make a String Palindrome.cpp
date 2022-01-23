class Solution
{
public:
    int dp[1001][1001];
    int fun(string &s, int i, int j)
    {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
        {
            return dp[i][j] = 2 + fun(s, i + 1, j - 1);
        }
        return dp[i][j] = max(fun(s, i + 1, j), fun(s, i, j - 1));
    }

    int minInsertions(string s)
    {
        memset(dp, -1, sizeof(dp));
        return s.size() - fun(s, 0, s.size() - 1);
    }
};
