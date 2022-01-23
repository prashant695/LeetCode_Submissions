class Solution
{
public:
    vector<int> findLonely(vector<int> &nums)
    {
        map<int, int> m;
        vector<int> v;

        for (auto x : nums)
            m[x]++;

        for (auto x : nums)
        {
            if (m[x] == 1 and m[x - 1] == 0 and m[x + 1] == 0)
                v.push_back(x);
        }

        return v;
    }
};