class Solution
{
public:
    int minimumOperations(vector<int> &v)
    {
        map<int, int> m1, m2;
        int a = INT_MAX, b = INT_MAX;
        vector<pair<int, int>> v1, v2;
        int x = 0, y = 0;

        if (v.size() == 1)
            return 0;

        for (int i = 0; i < v.size(); i++)
        {
            if (i % 2 == 0)
                m1[v[i]]++, x++;
            else
                m2[v[i]]++, y++;
        }

        for (auto x : m1)
            v1.push_back({x.second, x.first});

        for (auto x : m2)
            v2.push_back({x.second, x.first});

        sort(v1.begin(), v1.end());
        reverse(v1.begin(), v1.end());

        sort(v2.begin(), v2.end());
        reverse(v2.begin(), v2.end());

        if (v1[0].second != v2[0].second)
            return x - v1[0].first + y - v2[0].first;
        else
        {
            a = INT_MAX, b = INT_MAX;
            if (v2.size() >= 2)
                a = (x - v1[0].first + y - v2[1].first);

            if (v1.size() >= 2)
                b = (x - v1[1].first + y - v2[0].first);

            if (a == INT_MAX and b == INT_MAX)
                return min(x, y);

            return min(a, b);
        }
    }
};