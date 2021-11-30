// Approach 1

class Solution
{
public:
    vector<int> twoSum(vector<int> nums, int target)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[target - nums[i]])
            {
                if (i != m[target - nums[i]])
                {
                    return {i, m[target - nums[i]]};
                }
            }
        }
        return {};
    }
};
