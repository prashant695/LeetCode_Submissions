// Method_1
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string res = "";
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push('(');
            else if (s[i] == ')' && st.empty() == true)
                s[i] = '*';
            else if (s[i] == ')' && st.empty() == false)
                st.pop();
        }
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '*')
            {
            }
            else
                res += s[i];

        while (st.empty() == false)
            st.pop();
        s = "";
        for (int i = res.size() - 1; i >= 0; i--)
        {
            if (res[i] == ')')
                st.push(')');
            else if (res[i] == '(' && st.empty() == true)
                res[i] = '*';
            else if (res[i] == '(' && st.empty() == false)
                st.pop();
        }
        for (int i = 0; i < res.size(); i++)
            if (res[i] == '*')
            {
            }
            else
                s += res[i];
        return s;
    }
};

// Method_2
// Optimised
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string res = "";
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')' && st.empty() == true)
                s[i] = '*';
            else if (s[i] == ')' && st.empty() == false)
                st.pop();
        }

        while (st.empty() == false)
            s[st.top()] = '*', st.pop();

        for (int i = 0; i < s.size(); i++)
            if (s[i] == '*')
            {
            }
            else
                res += s[i];
        return res;
    }
};