class Solution
{
public:
    map<long long, long long> m;
    long long fun(vector<vector<int>> &v, int i)
    {
        if (i >= v.size())
            return 0;

        if (m.find(i) != m.end())
            return m[i];

        return m[i] = max(fun(v, i + 1), fun(v, i + 1 + v[i][1]) + v[i][0]);
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        return fun(questions, 0);
    }
};

