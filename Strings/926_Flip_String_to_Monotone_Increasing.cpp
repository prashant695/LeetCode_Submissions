class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int ans = 0, size = s.size(), cnt_zero = 0;
        for (int i = 0; i < size; i++)
        {
            s[i] == '0' ? cnt_zero++ : ans++;
            ans = max(ans, cnt_zero);
        }
        return size - ans;
    }
};