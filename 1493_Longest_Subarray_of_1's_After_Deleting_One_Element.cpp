class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int cntz = 0, j = 0, res = INT_MIN, k = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                cntz++;
            while (cntz > k)
            {
                if (nums[j] == 0)
                    cntz--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res - 1;
    }
};