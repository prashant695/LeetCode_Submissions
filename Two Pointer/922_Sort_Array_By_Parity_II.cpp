class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int i = 0, j = 0, eve = -1, odd = -1;
        int n = nums.size();
        while (i < n and j < n)
        {
            if ((nums[i] % 2 == 1 && i % 2 == 0))
            {
                eve = i;
            }
            if ((nums[j] % 2 == 0 && j % 2 == 1))
            {
                odd = j;
            }
            if (eve != -1 && odd != -1)
            {
                swap(nums[eve], nums[odd]);
                eve = -1;
                odd = -1;
            }
            if (eve == -1)
                i++;
            if (odd == -1)
                j++;
        }
        return nums;
    }
};