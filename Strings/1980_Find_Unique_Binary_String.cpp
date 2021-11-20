class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        map<string, int> m;
        int n = nums.size();
        string s(n, '0');
        int j = nums.size() - 1;
        for (int i = 0; i <= nums.size(); i++)
            m[nums[i]]++;
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
                if (m[s] == 0)
                    return s;
                else
                    s[j--] = '1';
            cout << s << endl;
            if (m[s] == 0)
                return s;
        }
        return "";
    }
};