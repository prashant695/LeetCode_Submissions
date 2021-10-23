class Solution
{
public:
    bool isPerfectSquare(int x)
    {
        int l = 1, h = x, mid;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (mid * mid == x)
                return 1;
            if (mid * mid > x and (mid - 1) * (mid - 1) < x)
                return 0;
            if (mid * mid < x)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return 0;
    }
};