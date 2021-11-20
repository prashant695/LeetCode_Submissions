class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string res(n, 'a');
        int i = n - 1;
        k -= n;
        while (k)
        {
            if (k >= 25)
            {
                res[i] = 'z';
                k -= 25;
                i--;
            }
            else
            {
                res[i] = k + 'a';
                k = 0;
            }
        }
        return res;
    }
};