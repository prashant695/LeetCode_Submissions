class Solution
{
public:
    void fun(int n, int i, string curr, vector<string> &res, int open, int close)
    {
        if (close > open or 2 * open > n)
            return;
        if (i == n)
        {
            if (open == close)
                res.push_back(curr);
            return;
        }

        fun(n, i + 1, curr + '(', res, open + 1, close);
        fun(n, i + 1, curr + ')', res, open, close + 1);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        fun(2 * n, 0, "", res, 0, 0);
        return res;
    }
};