class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {

        long long dp[10] = {1}, ans = 0, j = 8;
        dp[0] = 1;
        dp[1] = 10;
        dp[2] = 81;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] * j;
            j--;
        }
        for (int i = 0; i <= n; i++)
            ans += dp[i];
        return ans = n == 0 ? ans : ans - 1;
    }
};