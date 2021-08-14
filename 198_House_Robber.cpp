// Method_1
// Recursive - O(2^n)

class Solution
{
public:
    int sum = 0;
    int help(vector<int> &nums, int i)
    {
        if (i >= nums.size())
            return 0;
        sum = max(help(nums, i + 2) + nums[i], help(nums, i + 1));
        return sum;
    }
    int rob(vector<int> &nums)
    {
        help(nums, 0);
        return sum;
    }
};

// Method_2
// Memoized Recursion o(n) o(n)
class Solution
{
public:
    int dp[101];
    int help(vector<int> &nums, int i)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = max(help(nums, i + 2) + nums[i], help(nums, i + 1));
    }
    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return help(nums, 0);
    }
};

// Method_3
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int dp[101] = {0};
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return dp[n - 1];
    }
};

// Method_4
// o(n) o(1)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int x, y, tmp;
        x = nums[0];
        y = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            tmp = y;
            y = max(x + nums[i], y);
            x = tmp;
        }
        return y;
    }
};
