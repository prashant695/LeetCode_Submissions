class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int l = 1, h = 46340, mid;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (mid * mid == x)
                return mid;
            if (mid * mid > x and (mid - 1) * (mid - 1) < x)
                return mid - 1;
            if (mid * mid < x)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return mid;
    }
};