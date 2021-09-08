class Solution
{
public:
    int longestPalindrome(string s)
    {
        int m[26] = {0}, m2[26] = {0}, flg = 1, res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                m[s[i] - 'a']++;
            if (s[i] >= 'A' && s[i] <= 'Z')
                m2[s[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (m[i] % 2 == 0)
                res += m[i];
            if (m2[i] % 2 == 0)
                res += m2[i];
            if (m[i] % 2 == 1)
                res += m[i] - 1, flg = 0;
            if (m2[i] % 2 == 1)
                res += m2[i] - 1, flg = 0;
        }
        return res + (flg == 0);
    }
};