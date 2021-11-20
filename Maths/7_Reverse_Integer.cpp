class Solution
{
public:
    int reverse(int x)
    {
        long rev = 0, flg = 0;
        if (x < 0)
            flg = 1;
        x = abs(x);
        while (x)
        {
            rev = (x % 10) + (rev * 10);
            if (rev >= INT_MAX)
                return 0;
            if (flg && (rev * -1) <= INT_MIN)
                return 0;
            x /= 10;
        }
        if (flg)
            rev *= -1;
        return rev;
    }
};
