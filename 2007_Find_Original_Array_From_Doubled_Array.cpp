class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &nums)
    {
        int n = nums.size(), cnt = 0;
        vector<int> v;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0 && m[nums[i]] > 0 && m[nums[i] / 2] > 0)
            {
                if (nums[i] == 0 && m[0] >= 2)
                {
                    v.push_back(nums[i] / 2);
                    m[nums[i]]--;
                    m[nums[i] / 2]--;
                }
                else if (nums[i] != 0)
                {
                    v.push_back(nums[i] / 2);
                    m[nums[i]]--;
                    m[nums[i] / 2]--;
                }
            }
        }
        // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        if (v.size() * 2 == n)
            return v;
        else
            return {};
    }
};