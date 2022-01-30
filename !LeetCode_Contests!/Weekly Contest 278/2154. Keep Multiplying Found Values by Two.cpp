class Solution
{
public:
    int findFinalValue(vector<int> &nums, int o)
    {
        map<int, int> m;
        for (auto x : nums)
            m[x]++;

        while (m[o])
            o *= 2;

        return o;
    }
};