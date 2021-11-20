class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int low = 0, high = sqrt(c);
        long long l2, h2;

        while (low <= high)
        {
            l2 = low * low;
            h2 = high * high;
            if (l2 + h2 == c)
                return 1;
            else if ((l2 + h2) < c)
                low++;
            else
                high--;
        }
        return 0;
    }
};