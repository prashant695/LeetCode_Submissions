class Solution
{
public:
    map<int, int> m;
    int last;
    map<pair<int, int>, int> dp;
    bool fun(int k, int curr)
    {
        if (curr == last)
            return true;
        if (!m[curr])
            return false;

        if (dp.find({k, curr}) != dp.end())
        {
            return dp[{k, curr}];
        }

        bool a = false, b = false, c = false;

        // jump k-1
        if (k - 1 > 0 and m[curr + k - 1])
            a = fun(k - 1, curr + k - 1);

        // jump k
        if (m[curr + k])
            b = fun(k, curr + k);

        // jump k+1
        if (m[curr + k + 1])
            c = fun(k + 1, curr + k + 1);

        return dp[{k, curr}] = (a or b or c);
    }
    bool canCross(vector<int> &stones)
    {
        for (int i = 0; i < stones.size(); i++)
            m[stones[i]]++;
        last = stones[stones.size() - 1];
        // if(m[1]==0) return false;

        return fun(1, 1);
    }
};