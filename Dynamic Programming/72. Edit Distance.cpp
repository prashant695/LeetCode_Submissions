class Solution
{
public:
    int dp[501][501];
    int fun(string s, string y, int i, int j)
    {
        if (i == s.size())
            return y.size() - j;
        if (j == y.size())
            return s.size() - i;
        if (dp[i][j] >= 0)
            return dp[i][j];
        if (s[i] == y[j])
            return dp[i][j] = fun(s, y, i + 1, j + 1);
        return dp[i][j] = 1 + min(fun(s, y, i + 1, j), min(fun(s, y, i, j + 1), fun(s, y, i + 1, j + 1)));
    }
    int minDistance(string word1, string word2)
    {
        memset(dp, -1, sizeof(dp));
        int ans = fun(word1, word2, 0, 0);
        return ans;
    }
};
