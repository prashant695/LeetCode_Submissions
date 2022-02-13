class Solution
{
public:
    long long minimumRemoval(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        long long cnt, res = LONG_LONG_MAX;

        int n = nums.size();
        long long pre[n];

        pre[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            pre[i] = nums[i] + pre[i - 1];

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                cnt = (pre[n - 1] - pre[i]) - (1ll * nums[i] * (n - 1 - i));
            }
            else if (i == n - 1)
            {
                cnt = pre[i - 1];
            }
            else
            {
                cnt = pre[i - 1] + (pre[n - 1] - pre[i]) - (1ll * nums[i] * (n - 1 - i));
            }
            res = min(res, cnt);
        }
        return res;
    }
};