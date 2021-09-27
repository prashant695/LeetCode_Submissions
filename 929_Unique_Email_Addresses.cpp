class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> s;
        string temp;
        int flg = 0, alpha = 0;
        for (int i = 0; i < emails.size(); i++)
        {
            temp = "";
            flg = 0;
            alpha = 0;
            for (int j = 0; j < emails[i].size(); j++)
            {
                if (emails[i][j] == '.' && alpha == 0)
                    continue;
                else if (emails[i][j] == '+')
                    flg = 1;
                else if (emails[i][j] == '@')
                    alpha = 1;

                if (flg == 0)
                    temp += emails[i][j];
                else if (alpha == 1)
                    temp += emails[i][j];
            }

            s.insert(temp);
        }
        return s.size();
    }
};