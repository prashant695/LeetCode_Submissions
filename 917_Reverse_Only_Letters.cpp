class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while ((s[i] >= 33 && s[i] <= 64) || (s[i] >= 91 && s[i] <= 96) && (i < j))
            {
                i++;
            }
            while ((s[j] >= 91 && s[j] <= 96) || (s[j] >= 33 && s[j] <= 64) && (i < j))
            {
                j--;
            }
            if (i < j)
                swap(s[i], s[j]);
            i++, j--;
        }
        return s;
    }
};