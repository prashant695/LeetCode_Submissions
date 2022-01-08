class Solution
{
public:
    string capitalizeTitle(string str)
    {
        stringstream s(str);
        string word;
        string res;
        int count = 0;
        while (s >> word)
        {
            if (word.size() == 1 || word.size() == 2)
            {
                transform(word.begin(), word.end(), word.begin(), ::tolower);
            }
            else
            {
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                word[0] = toupper(word[0]);
            }
            res += word + ' ';
        }
        res = res.substr(0, res.size() - 1);
        return res;
    }
};