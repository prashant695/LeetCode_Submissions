class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int n1 = num1.size(), n2 = num2.size();
        int i = n1 - 1, j = n2 - 1, carry = 0, x = 0;
        char y;
        string res = "";
        while (i >= 0 || j >= 0)
        {
            x = 0;
            if (i >= 0)
                x += num1[i] - '0', i--;
            if (j >= 0)
                x += num2[j] - '0', j--;
            x += carry;
            if (x >= 10)
                carry = 1;
            else
                carry = 0;
            y = ((x % 10) + '0');
            res = y + res;
        }
        if (carry)
            res = "1" + res;
        return res;
    }
};