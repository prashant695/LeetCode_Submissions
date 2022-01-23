class Solution
{
public:
    map<pair<int, int>, int> m;
    bool ispali(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return 0;
            i++, j--;
        }
        return 1;
    }
    int part(int idx, string &s, int cnt)
    {
        if (idx == s.size() or ispali(idx, s.size() - 1, s))
            return 0;

        if (m.find({idx, cnt}) != m.end())
            return m[{idx, cnt}];

        int mi = INT_MAX;

        for (int i = idx; i < s.size(); i++)
            if (ispali(idx, i, s))
                mi = min(mi, part(i + 1, s, cnt) + 1);

        return m[{idx, cnt}] = mi;
    }
    int minCut(string s)
    {
        return part(0, s, 0);
    }
};