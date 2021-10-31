class Solution
{
public:
    int cnt = 0;

    int solve(vector<int> &nums, int target, int i, int val)
    {
        if (i == nums.size() - 1)
        {
            if (val == target)
                return 1;
            return 0;
        }

        solve(nums, target, i + 1, val + nums[i + 1]);
        solve(nums, target, i + 1, val - nums[i + 1]);
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        solve(nums, target, -1, 0);
        return cnt;
    }
};