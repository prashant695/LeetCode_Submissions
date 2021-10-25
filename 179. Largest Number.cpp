class Solution
{
public:
    bool static cmp(string a, string b)
    {
        return a + b > b + a;
    }
    string largestNumber(vector<int> &nums)
    {
        string s;
        vector<string> v;
        for (int i = 0; i < nums.size(); i++)
            v.push_back(to_string(nums[i]));

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < v.size(); i++)
            s += v[i];
        if (s[0] == '0' and s[s.size() - 1] == '0')
            return "0";
        return s;
    }
};