class Solution
{
public:
    int dp[601][101][101];
    int help(vector<string> &s, int m, int n, int curr_m, int curr_n, int i)
    {
        if (i >= s.size())
            return 0;
        else if (curr_m <= 0 && curr_n <= 0)
            return 0;
        else if (dp[i][curr_m][curr_n] != -1)
            return dp[i][curr_m][curr_n];

        int o = 0, z = 0;
        for (int j = 0; j < s[i].size(); j++)
        {
            if (s[i][j] == '0')
                z++;
            else
                o++;
        }
        if (z > curr_m || o > curr_n)
            return dp[i][curr_m][curr_n] = help(s, m, n, curr_m, curr_n, i + 1);
        return dp[i][curr_m][curr_n] = max(help(s, m, n, curr_m, curr_n, i + 1), (help(s, m, n, curr_m - z, curr_n - o, i + 1) + 1));
    }
    int findMaxForm(vector<string> &s, int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return help(s, m, n, m, n, 0);
    }
};