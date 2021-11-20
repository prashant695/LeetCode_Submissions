class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> v(n, 0);
        int i = 0, k = 0;
        for (; k < n; i++, k += 2)
        {
            v[k] = nums[i];
        }
        k = 1;
        for (; k < n; i++, k += 2)
        {
            v[k] = nums[i];
        }
        return v;
    }
};