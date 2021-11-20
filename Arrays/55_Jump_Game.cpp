class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int res = nums[0];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (res < i)
                return false;
            res = max(res, i + nums[i]);
        }
        return (res >= nums.size() - 1);
    }
};