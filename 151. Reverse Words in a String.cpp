// Bruteforce
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> v;
        string x, res = "";
        for (int i = 0; i < s.size(); i++)
        {
            x = "";
            if (s[i] != ' ')
            {
                x += s[i], i++;
                while (i < s.size() and s[i] != ' ')
                    x += s[i], i++;
                v.push_back(x);
            }
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            res += v[i];
            if (i != 0)
                res += ' ';
        }
        return res;
    }
};

// Two pointers
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size(), i = n - 1, j = -1, flg = 0;
        string res = "";
        while (i >= 0)
        {
            if (s[i] != ' ')
            {
                j = i;
                flg++;
                while (j >= 0 and s[j] != ' ')
                {
                    j--;
                }
                if (flg >= 2)
                    res += ' ';
                res += s.substr(j + 1, abs(i - j));
                i = j;
            }
            i--;
        }
        return res;
    }
};