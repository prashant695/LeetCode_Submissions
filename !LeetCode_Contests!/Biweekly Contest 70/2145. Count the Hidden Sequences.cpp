class Solution
{
public:
    vector<long long> vv;
    void fun(vector<int> &diff, long long x)
    {
        vv.push_back(x);
        for (long long i = 0; i < diff.size(); i++)
        {
            long long val = vv[i] + diff[i];
            vv.push_back(val);
        }
    }

    long long numberOfArrays(vector<int> &diff, long long lower, long long upper)
    {
        fun(diff, lower);
        long long mi = *min_element(vv.begin(), vv.end());
        long long ma = *max_element(vv.begin(), vv.end());

        long long x = upper - (ma + (lower - mi)) + 1;
        return x < 0 ? 0 : x;
    }
};
