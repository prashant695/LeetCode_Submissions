class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        string t = "", res = s;
        if (k == 1)
        {
            for (int i = 0; s[i]; i++)
            {
                t = s.substr(i) + s.substr(0, i);
                res = min(res, t);
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};