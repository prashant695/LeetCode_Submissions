class Solution
{
public:
    vector<string> res, v = {"a", "e", "i", "o", "u"};
    int dp[51][5];
    int cnt = 0;
    int help(string curr, int n, int pos)
    {
        int t = cnt;
        if (dp[n][pos] != -1)
            return dp[n][pos];
        if (n == 0)
        {
            return 1;
        }
        for (int i = pos; i < 5; i++)
        {
            cnt += help(curr + v[i], n - 1, i);
        }
        dp[n][pos] = cnt - t;
        return 0;
    }
    int countVowelStrings(int n)
    {
        memset(dp, -1, sizeof(dp));
        help("", n, 0);
        return cnt;
    }
};