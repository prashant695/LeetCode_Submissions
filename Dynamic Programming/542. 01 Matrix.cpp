class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> dp(r, vector<int>(c, INT_MAX - 1));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                if (i >= 1)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if (j >= 1)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        for (int i = r - 1; i >= 0; i--)
        {
            for (int j = c - 1; j >= 0; j--)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                if (i < r - 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if (j < c - 1)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }
        return dp;
    }
};