class Solution
{
public:
    int dp[1001][2][1];
    int fun(int idx, vector<int> &prices, int is_empty, int t)
    {
        if (idx >= prices.size() or t == 1)
        {
            return 0;
        }
        if (dp[idx][is_empty][t] != -1)
            return dp[idx][is_empty][t];
        if (is_empty == 1)
        {
            return dp[idx][is_empty][t] =
                       max(fun(idx + 1, prices, 0, t) - prices[idx], (fun(idx + 1, prices, is_empty, t)));
        }
        if (is_empty == 0)
        {
            return dp[idx][is_empty][t] =
                       max(fun(idx + 1, prices, 1, t + 1) + prices[idx], (fun(idx + 1, prices, is_empty, t)));
        }
        return 0;
    }
    int maximumDifference(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int x = fun(0, nums, 1, 0);
        return x == 0 ? -1 : x;
    }
};