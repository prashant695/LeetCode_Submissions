class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp;
        dp = cost;
        for (int i = 2; i < cost.size(); i++)
        {
            dp[i] += min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};