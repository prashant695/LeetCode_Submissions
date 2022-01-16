class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> v;

        for (int i = 0; i < s.size(); i += k)
            v.push_back(s.substr(i, k));

        if (s.size() % k == 0)
            return v;
        else
        {
            for (int i = 0; i < k - s.size() % k; i++)
                v[v.size() - 1] += fill;
        }

        return v;
    }
};

