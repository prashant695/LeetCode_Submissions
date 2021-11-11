class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        stack<char> st;
        int flg = 0;
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push('(');
            }
            else
            {
                st.pop();
            }
            if (st.size() == 1 and flg == 0)
                s[i] = '*', flg = 1;
            if (st.size() == 0 and flg == 1)
                s[i] = '*', flg = 0;
        }

        for (int i = 0; i < s.size(); i++)
            if (s[i] != '*')
                res += s[i];
        return res;
    }
};