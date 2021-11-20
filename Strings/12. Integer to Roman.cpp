class Solution
{
public:
    string intToRoman(int num)
    {
        string res = "";
        while (num > 0)
        {
            if (num >= 1000)
            {
                res += 'M';
                num -= 1000;
            }
            else if (num >= 900 and num < 1000)
            {
                res += "CM";
                num -= 900;
            }
            else if (num >= 500)
            {
                res += 'D';
                num -= 500;
            }
            else if (num >= 400 and num < 500)
            {
                res += "CD";
                num -= 400;
            }
            else if (num >= 100)
            {
                res += "C";
                num -= 100;
            }
            else if (num >= 90 and num < 100)
            {
                res += "XC";
                num -= 90;
            }
            else if (num >= 50)
            {
                res += "L";
                num -= 50;
            }
            else if (num >= 40 and num < 50)
            {
                res += "XL";
                num -= 40;
            }
            else if (num >= 10)
            {
                res += "X";
                num -= 10;
            }
            else if (num >= 9 and num < 10)
            {
                res += "IX";
                num -= 9;
            }
            else if (num >= 5)
            {
                res += "V";
                num -= 5;
            }
            else if (num >= 4 and num < 5)
            {
                res += "IV";
                num -= 4;
            }
            else if (num >= 1)
            {
                res += "I";
                num -= 1;
            }
        }
        return res;
    }
};