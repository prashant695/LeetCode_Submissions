class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = upper_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end())
                v.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return v.size();
    }
    int kIncreasing(vector<int> &arr, int k)
    {
        int cnt = 0;
        vector<vector<int>> vv;
        vector<int> v;
        for (int i = 0; i < arr.size(); i++)
        {
            v.clear();
            for (int j = i; j < arr.size() and arr[j] != -1; j += k)
                v.push_back(arr[j]), arr[j] = -1;
            vv.push_back(v);
        }

        for (int i = 0; i < vv.size(); i++)
            cnt += (vv[i].size() - lengthOfLIS(vv[i]));
        return cnt;
    }
};