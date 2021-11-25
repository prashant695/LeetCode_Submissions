class Solution
{
public:
    int getLucky(string s, int k)
    {
        int num = 0, cnt = 0;
        int s2 = 0;
        for (int i = 0; i < s.size(); i++)
            s2 += (int(s[i]) - 96) % 10 + (int(s[i]) - 96) / 10;

        num = s2;
        k--;

        if (k == 0)
            return num;

        while (k--)
        {
            cnt = 0;
            while (num)
            {
                cnt += (num % 10);
                num /= 10;
            }
            num = cnt;
        }
        return cnt;
    }
};