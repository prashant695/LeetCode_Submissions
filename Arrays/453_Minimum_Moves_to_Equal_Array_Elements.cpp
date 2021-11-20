class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int minn = INT_MAX, res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (minn > nums[i])
                minn = nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
            res += (nums[i] - minn);
        return res;
    }
};