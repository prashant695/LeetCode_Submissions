// Method_1
// Brute Force
// O(n2)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int s = 0, res = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            s = nums[i];
            res = max(res, s);
            for (int j = i + 1; j < nums.size(); j++)
            {
                s += nums[j];
                res = max(res, s);
            }
        }
        return res;
    }
};

// Kadane's Algorithm
// O(n)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr = nums[0], best = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (curr >= 0)
                curr += nums[i];
            else
                curr = nums[i];
            best = max(curr, best);
        }
        return best;
    }
};