class Solution
{
public:
    long long int exp(long long x, long long int n, int M)
    {
        if (n == 0)
            return 1;
        else if (n % 2 == 0)
            return exp((x * x) % M, n / 2, M);

        else
            return (x * exp((x * x) % M, (n - 1) / 2, M)) % M;
    }
    int countGoodNumbers(long long n)
    {
        int mod = 1e9 + 7;
        long long int x = exp(5, n / 2, mod);
        long long int y = exp(4, n / 2, mod);
        long long int res = ((x % mod) * (y % mod)) % mod;
        if (n & 1)
            res = ((res % mod) * (5 % mod)) % mod;
        return res;
    }
};