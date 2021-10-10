class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        vector<int> res;
        map<int, int> m, m2, m3;
        for (auto it : nums1)
            m[it]++;
        for (auto it : nums2)
            m2[it]++, nums1.push_back(it);
        for (auto it : nums3)
            m3[it]++, nums1.push_back(it);

        for (auto x : nums1)
        {
            if (m[x] && m2[x])
            {
                res.push_back(x);
                m[x] = 0;
                m2[x] = 0;
            }
            if (m3[x] && m2[x])
            {
                res.push_back(x);
                m3[x] = 0;
                m2[x] = 0;
            }
            if (m3[x] && m[x])
            {
                res.push_back(x);
                m3[x] = 0;
                m[x] = 0;
            }
        }
        return res;
    }
};