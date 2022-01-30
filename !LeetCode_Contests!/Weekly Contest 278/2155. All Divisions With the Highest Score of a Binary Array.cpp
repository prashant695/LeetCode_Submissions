class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        int one = 0, zero = 0, ma = -1;
        vector<int> res;
        vector<pair<int, int>> v;

        for (auto x : nums)
            if (x == 1)
                one++;

        v.push_back({one, 0});

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zero++;
            else
                one--;

            v.push_back({one + zero, i + 1});
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first > ma)
                ma = v[i].first;
        }

        for (int i = 0; i < v.size(); i++)
            if (v[i].first == ma)
                res.push_back(v[i].second);

        return res;
    }
};