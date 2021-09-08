class Solution
{
public:
    int minOperations(string s)
    {
        string t = "";
        int cnt = 0, cnt2 = 0;
        for (int i = 0; s[i]; i++)
        {
            if (i % 2 == 0)
                t += '0';
            else
                t += '1';
        }

        for (int i = 0; s[i]; i++)
        {
            if (s[i] != t[i])
                cnt++;
        }

        t = "";

        for (int i = 0; s[i]; i++)
        {
            if (i % 2 == 0)
                t += '1';
            else
                t += '0';
        }

        for (int i = 0; s[i]; i++)
        {
            if (s[i] != t[i])
                cnt2++;
        }
        return min(cnt, cnt2);
    }
};