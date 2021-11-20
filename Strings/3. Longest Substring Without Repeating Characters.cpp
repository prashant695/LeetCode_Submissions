class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        int a = 0, b = 0, res = 1, n = s.size();
        map<char, int> m;

        while (b < s.size())
        {
            if (m[s[b]] == 1)
            {
                char ch = s[b];
                while (m[ch] == 1)
                {
                    m[s[a]]--;
                    a++;
                }
            }
            else
            {
                m[s[b]]++;
                b++;
            }
            res = max(res, b - a);
        }
        return res;
    }
};