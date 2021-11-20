class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    int cnt = 0, j = 0;
    for (int i = 0; i < t.size(); i++)
    {
      if (t[i] == s[j])
        cnt++, j++;
    }
    return cnt == s.size();
  }
  bool static cmp(string a, string b)
  {
    if (a.size() != b.size())
      return a.size() > b.size();
    return a < b;
  }
  int findLUSlength(vector<string> &s)
  {
    sort(s.begin(), s.end(), cmp);
    int flg = 0;

    for (int i = 0; i < s.size(); i++)
    {
      flg = 0;
      for (int j = 0; j < s.size(); j++)
      {
        if (isSubsequence(s[i], s[j]))
        {
          flg++;
        }
      }
      if (flg <= 1)
      {
        return s[i].size();
      }
    }
    return -1;
  }
};