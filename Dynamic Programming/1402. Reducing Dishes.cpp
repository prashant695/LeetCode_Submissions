class Solution
{
public:
    int dp[501][501];
    int fun(vector<int> &s, int i, int cnt)
    {
        if (i >= s.size())
            return 0;

        if (dp[i][cnt] != -1)
            return dp[i][cnt];

        return dp[i][cnt] = max(fun(s, i + 1, cnt + 1) + s[i] * cnt, fun(s, i + 1, cnt));
    }
    int maxSatisfaction(vector<int> &s)
    {
        sort(s.begin(), s.end());
        memset(dp, -1, sizeof(dp));
        return fun(s, 0, 1);
    }
};
