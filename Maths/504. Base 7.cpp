class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        int sign = 0;
        string res = "";
        if (num < 0)
        {
            num = abs(num);
            sign = 1;
        }
        while (num)
        {
            res += (num % 7) + '0';
            num /= 7;
        }
        if (sign)
            res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};