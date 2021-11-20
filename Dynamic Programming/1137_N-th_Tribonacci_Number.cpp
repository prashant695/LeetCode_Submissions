class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        int a = 0, b = 1, c = 1, d, e;
        for (int i = 3; i <= n; i++)
        {
            d = b;
            e = c;
            c = a + b + c;
            a = d;
            b = e;
        }
        return c;
    }
};