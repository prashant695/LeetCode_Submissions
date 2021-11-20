// Optimised Brute force
// TLE😞

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        map<int, int> m;
        vector<vector<int>> res;
        set<vector<int>> s;
        vector<int> v;
        int sz;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]]++;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]--;
            for (int j = i + 1; j < nums.size(); j++)
            {
                m[nums[j]]--;
                if (m[-(nums[i] + nums[j])])
                {
                    sz = s.size();
                    v = {nums[i], nums[j], -(nums[i] + nums[j])};
                    sort(v.begin(), v.end());
                    s.insert(v);
                    if (s.size() != sz)
                        res.push_back(v);
                }
                m[nums[j]]++;
            }
            m[nums[i]]++;
        }
        return res;
    }
};

// Two pointer approach
// Accepted😃

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int low, high, a, target;

        for (int i = 0; i < nums.size();)
        {
            a = nums[i];
            low = i + 1;
            high = nums.size() - 1;
            target = -a;
            while (low < high)
            {
                if (nums[low] + nums[high] < target)
                    low++;
                else if (nums[low] + nums[high] > target)
                    high--;
                else
                {
                    res.push_back({nums[low], nums[high], a});
                    int prev_low = low;
                    int prev_high = high;
                    while (low < nums.size() and nums[low] == nums[prev_low])
                        low++;
                    while (high > 0 and nums[high] == nums[prev_high])
                        high--;
                }
            }
            int prev_a = a;
            while (i < nums.size() and nums[i] == prev_a)
                i++;
        }
        return res;
    }
};