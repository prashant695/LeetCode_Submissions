class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int flg = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= 0)
                nums[i] = nums.size() + 1;
            if (nums[i] == nums.size())
                flg = 1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i]) < nums.size() && abs(nums[i]) > 0)
                if (nums[abs(nums[i])] > 0)
                    nums[abs(nums[i])] *= -1;
        }

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > 0)
                return i;
        if (flg == 0)
            return nums.size();
        return nums.size() + 1;
    }
};
