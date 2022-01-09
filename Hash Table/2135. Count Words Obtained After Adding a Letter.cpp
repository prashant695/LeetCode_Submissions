class Solution
{
public:
    int wordCount(vector<string> &s, vector<string> &t)
    {
        map<string, int> m;
        string ss;
        int cnt = 0, flg;
        for (int i = 0; i < s.size(); i++)
        {
            sort(s[i].begin(), s[i].end());
            m[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            sort(t[i].begin(), t[i].end());
            for (int j = 0; j < t[i].size(); j++)
            {
                flg = 0;
                ss = t[i].substr(0, j);
                ss += t[i].substr(j + 1, t[i].size());
                if (m.find(ss) != m.end())
                {
                    for (int k = 0; k < ss.size(); k++)
                        if (t[i][j] == ss[k])
                            flg = 1;
                    if (flg == 0)
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};