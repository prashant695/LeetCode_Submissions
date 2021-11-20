class Solution
{
public:
    int dp[1000][1000];
    int palindrome(string s, int i, int j)
    {
        if (s.size() == 2)
        {
            if (s[0] == s[1])
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
        int x = s[0];
        int y = s[s.size() - 1];

        if (x == y && dp[i + 1][j - 1])
            dp[i][j] = 1;
        else
            dp[i][j] = 0;

        return dp[i][j];
    }
    int countSubstrings(string s)
    {
        memset(dp, -1, sizeof(dp));
        string temp;
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            temp = s[i];
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++)
            {
                temp += s[j];
                res += palindrome(temp, i, j);
            }
        }
        return res + s.size();
    }
};