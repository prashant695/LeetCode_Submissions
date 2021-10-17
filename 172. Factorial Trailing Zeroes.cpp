class Solution
{
public:
    int trailingZeroes(int n)
    {
        int five = 5, res = 0, cnt = 0;
        while (1)
        {
            res = n / five;
            if (res == 0)
                return cnt;
            cnt += n / five;
            five *= 5;
        }
        return cnt;
    }
};