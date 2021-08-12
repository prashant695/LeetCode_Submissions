class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        int cnt = 0, x, y;
        for (int i = 0; i < tokens.size(); i++)
        {

            if (tokens[i] == "*")
            {
                x = s.top();
                s.pop();
                y = s.top();
                s.pop();
                cnt = (x * y);
                s.push(x * y);
            }
            else if (tokens[i] == "+")
            {
                x = s.top();
                s.pop();
                y = s.top();
                s.pop();
                cnt = (x + y);
                s.push(x + y);
            }
            else if (tokens[i] == "-")
            {
                x = s.top();
                s.pop();
                y = s.top();
                s.pop();
                cnt = (y - x);
                s.push(y - x);
            }
            else if (tokens[i] == "/")
            {
                x = s.top();
                s.pop();
                y = s.top();
                s.pop();
                cnt = (y / x);
                s.push(y / x);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return cnt;
    }
};