class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        int cnt = 0, ma, mi;
        for (int i = 0; i < nums.size(); i++)
        {
            ma = INT_MIN, mi = INT_MAX;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                {
                    ma = max(ma, nums[j]);
                    mi = min(mi, nums[j]);
                }
            }

            if (ma > nums[i] and mi < nums[i])
                cnt++;
        }
        return cnt;
    }
};