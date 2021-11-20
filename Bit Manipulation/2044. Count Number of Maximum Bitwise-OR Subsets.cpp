class Solution
{
public:
    int cnt = 0;
    void fun(vector<int> &nums, int orr, int i, int curr_or)
    {
        if (i == nums.size())
        {
            if (curr_or == orr)
                cnt++;
            return;
        }

        fun(nums, orr, i + 1, curr_or | nums[i]);
        fun(nums, orr, i + 1, curr_or);
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int orr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            orr = orr | nums[i];
        }

        fun(nums, orr, 0, 0);
        return cnt;
    }
};