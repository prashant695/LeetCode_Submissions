class Solution
{
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        vector<int> v, v2, res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
                v.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
        }

        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());
        reverse(v2.begin(), v2.end());

        for (int i = 0; i < v.size(); i++)
        {
            res.push_back(v[i]);
            if (i < v2.size())
                res.push_back(v2[i]);
        }
        return res;
    }
};