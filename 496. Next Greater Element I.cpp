class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> m;
        vector<int> v;
        int j;
        for (int i = 0; i < nums2.size(); i++)
        {
            m[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            j = m[nums1[i]];
            j++;
            while (j < nums2.size() && nums2[j] < nums1[i])
                j++;
            if (j == nums2.size())
                v.push_back(-1);
            else
                v.push_back(nums2[j]);
        }
        return v;
    }
};