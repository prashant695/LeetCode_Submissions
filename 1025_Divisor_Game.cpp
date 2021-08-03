// Method_0
// Using Recursion
// exponential
class Solution
{
public:
    bool help(int n)
    {
        if (n == 1)
            return 0;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0 && help(n - i) == 0)
                return 1;
        }
        return 0;
    }
    bool divisorGame(int n)
    {
        return help(n);
    }
};

// Method_1
// Using DP memoization
// o(n2)
class Solution
{
public:
    int dp[1001];
    bool help(int n)
    {
        if (dp[n] != -1)
            return dp[n];
        if (n == 1)
            return dp[1] = 0;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0 && help(n - i) == 0)
                return dp[n] = 1;
        }
        return dp[n] = 0;
    }
    bool divisorGame(int n)
    {
        memset(dp, -1, sizeof(dp));
        return help(n);
    }
};

// Method_2
// Using DP memoization
// o(n*n^1/2)
class Solution
{
public:
    int dp[1001];
    bool help(int n)
    {
        if (dp[n] != -1)
            return dp[n];
        if (n == 1)
            return dp[1] = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0 && help(n - i) == 0)
                return dp[n] = 1;
            if (i != 1)
                if (n % i == 0 && help(n - n / i) == 0)
                    return dp[n] = 1;
        }
        return dp[n] = 0;
    }
    bool divisorGame(int n)
    {
        memset(dp, -1, sizeof(dp));
        return help(n);
    }
};

// Method_3
// o(1)

class Solution
{
public:
    bool divisorGame(int n)
    {
        return n % 2 == 0;
    }
};