class Solution
{
public:
    vector<string> v;
    void fun(string s, string res, int i)
    {
        if (i == s.size())
        {
            v.push_back(res);
            return;
        }
        if (s[i] >= '0' and s[i] <= '9')
            fun(s, res + s[i], i + 1);
        else
        {
            char x = toupper(s[i]);
            char y = tolower(s[i]);
            fun(s, res + x, i + 1);
            fun(s, res + y, i + 1);
        }
    }
    vector<string> letterCasePermutation(string s)
    {
        fun(s, "", 0);
        return v;
    }
};