class Solution
{
public:
    bool static cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
    {
        if (p1.second.first == p2.second.first)
            return p1.second.second < p2.second.second;
        return p1.second.first < p2.second.first;
    }
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int current = 0;
        vector<pair<int, pair<int, int>>> v;

        for (int i = 0; i < trips.size(); i++)
        {
            v.push_back({trips[i][0], {trips[i][1], 1}});
            v.push_back({trips[i][0], {trips[i][2], 0}});
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].second.second == 1)
                current += v[i].first;
            else
                current -= v[i].first;

            if (current > capacity)
                return 0;
        }
        return 1;
    }
};