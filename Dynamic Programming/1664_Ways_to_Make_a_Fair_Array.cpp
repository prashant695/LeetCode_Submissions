class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int n = nums.size(), cnt = 0;
        if (n == 1)
            return 1;
        int aftereven[n], afterodd[n], beforeven[n], beforeodd[n];

        int even = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                even += nums[i];
            else
                odd += nums[i];

            beforeven[i] = even;
            beforeodd[i] = odd;
        }

        even = 0, odd = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i % 2 == 0)
                even += nums[i];
            else
                odd += nums[i];

            aftereven[i] = even;
            afterodd[i] = odd;
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (aftereven[i + 1] == afterodd[i + 1])
                    cnt++;
            }
            else if (i == n - 1)
            {
                if (beforeven[i - 1] == beforeodd[i - 1])
                    cnt++;
            }
            else
            {
                if (beforeven[i - 1] + afterodd[i + 1] == beforeodd[i - 1] + aftereven[i + 1])
                    cnt++;
            }
        }
        return cnt;
    }
};