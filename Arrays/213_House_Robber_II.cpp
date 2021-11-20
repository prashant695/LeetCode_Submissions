class Solution
{
public:
    int robb(vector<int> &nums)
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
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        vector<int> v;
        int x;
        for (int i = 0; i < nums.size() - 1; i++)
            v.push_back(nums[i]);
        x = robb(v);
        v.clear();
        for (int i = 1; i < nums.size(); i++)
            v.push_back(nums[i]);
        x = max(x, robb(v));
        return x;
    }
};