class Solution
{
public:
    int calculate(string s)
    {
        string x, y;
        vector<string> s2;
        string tmp = "";
        int p = 0, n = 0, c, cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            else if (s[i] == '/' or s[i] == '*' or s[i] == '+' or s[i] == '-')
            {
                s2.push_back(tmp), tmp = "";
                if (s[i] == '/')
                    s2.push_back("/");
                else if (s[i] == '*')
                    s2.push_back("*");
                else if (s[i] == '+')
                    s2.push_back("+");
                else if (s[i] == '-')
                    s2.push_back("-");
            }
            else
                tmp += s[i];
        }
        if (tmp != "")
            s2.push_back(tmp);
        stack<string> st;
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == "/")
            {
                x = st.top();
                y = s2[i + 1];
                st.pop();
                string z = to_string(stoi(x) / stoi(y));
                st.push(z);
                i++;
            }
            else if (s2[i] == "*")
            {
                x = st.top();
                y = s2[i + 1];
                st.pop();
                string z = to_string(stoi(x) * stoi(y));
                st.push(z);
                i++;
            }
            else
                st.push(s2[i]);
        }
        if (s2.size() == 1)
            return stoi(s2[0]);

        s2.clear();
        while (st.empty() == false)
        {
            x = st.top();
            st.pop();
            s2.push_back(x);
        }
        reverse(s2.begin(), s2.end());
        if (s2.size() == 1)
            return stoi(s2[0]);
        int res = stoi(s2[0]);
        for (int i = 1; i < s2.size(); i++)
        {
            if (s2[i] == "+")
                res += stoi(s2[i + 1]), i++;
            else if (s2[i] == "-")
                res -= stoi(s2[i + 1]), i++;
        }
        return res;
    }
};