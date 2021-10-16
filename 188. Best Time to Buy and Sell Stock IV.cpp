class Solution
{
public:
    int dp[1001][2][101];
    int fun(int idx, vector<int> &prices, int is_empty, int t, int k)
    {
        if (idx >= prices.size() or t == k)
        {
            return 0;
        }
        if (dp[idx][is_empty][t] != -1)
            return dp[idx][is_empty][t];
        if (is_empty == 1)
        {
            return dp[idx][is_empty][t] =
                       max(fun(idx + 1, prices, 0, t, k) - prices[idx], (fun(idx + 1, prices, is_empty, t, k)));
        }
        if (is_empty == 0)
        {
            return dp[idx][is_empty][t] =
                       max(fun(idx + 1, prices, 1, t + 1, k) + prices[idx], (fun(idx + 1, prices, is_empty, t, k)));
        }
        return 0;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        int x = fun(0, prices, 1, 0, k);
        return x;
    }
};
