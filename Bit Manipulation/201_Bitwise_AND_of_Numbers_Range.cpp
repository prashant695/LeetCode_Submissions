//method-0 Bruteforce
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = left;
        for (int i = ans + 1; i <= right; i++)
            ans &= i;
        return ans;
    }
};

//method-2 optimised
class Solution
{
public:
    long long highestpower(int n)
    {
        long long i = 0;
        while (pow(2, i) < n)
            i++;
        return pow(2, i);
    }
    int rangeBitwiseAnd(int left, int right)
    {
        long long i, ans, a = highestpower(left);
        long long b = highestpower(right);

        if (a != b && left != a && right != b)
            return 0;
        else if (left == right)
            return left;
        else
        {
            ans = left;
            for (i = left + 1; i <= right; i++)
                ans = ans & i;
        }
        return ans;
    }
};

//method-3 Best
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int cnt = 0;
        while (left != right)
        {
            cnt++;
            left /= 2, right /= 2;
        }
        return left << cnt;
    }
};