class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int x, x2;
        vector<int> v;
        for (int i = 0; i < s.size(); i++)
        {
            x = 0;
            if (s[i] >= '0' && s[i] <= '9')
            {
                x = x * 10 + (s[i] - '0');
                i++;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9')
                {
                    x = x * 10 + (s[i] - '0');
                    i++;
                }
                v.push_back(x);
            }
        }
        for (int i = 1; i < v.size(); i++)
            if (v[i] <= v[i - 1])
                return false;
        return true;
    }
};