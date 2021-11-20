class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int cnt = 0;
        while (x or y)
        {
            if (x % 2 + y % 2 == 1)
                cnt++;
            x /= 2, y /= 2;
        }
        return cnt;
    }
};