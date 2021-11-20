class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size(), val = 0, cnt = 0;
        int pre[n + 1], suff[n + 1], cntstar[n + 1];
        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '|')
                val = i;
            pre[i] = val;
            if (s[i] == '*')
                cnt++;
            cntstar[i] = cnt;
        }

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '|')
                val = i;
            suff[i] = val;
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int x = cntstar[pre[queries[i][1]]];
            int y = cntstar[suff[queries[i][0]]];
            if ((x - y) < 0)
                x = y;
            res.push_back(x - y);
        }
        return res;
    }
};
