class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int dp[10][10];
        int res = 0, cnt = 0;
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < dominoes.size(); i++)
        {
            if (dominoes[i][1] > dominoes[i][0])
                swap(dominoes[i][1], dominoes[i][0]);

            dp[dominoes[i][0]][dominoes[i][1]]++;
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (dp[i][j] >= 1)
                    cnt = dp[i][j], res += (cnt * (cnt - 1)) / 2;
            }
        }
        return res;
    }
};