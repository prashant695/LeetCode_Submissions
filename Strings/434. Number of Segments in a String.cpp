class Solution
{
public:
    int countSegments(string s)
    {
        if (s.size() == 0)
            return 0;
        int cnt = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] != ' ' and s[i + 1] == ' ')
                cnt++;
        }
        if (s[s.size() - 1] != ' ')
            cnt++;
        return cnt;
    }
};