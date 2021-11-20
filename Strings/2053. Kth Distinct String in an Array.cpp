class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        map<string, int> m;
        int cnt = 0;
        string res = "";
        for (int i = 0; i < arr.size(); i++)
            m[arr[i]]++;

        for (int i = 0; i < arr.size(); i++)
        {
            if (m[arr[i]] == 1)
            {
                cnt++;
                if (cnt == k)
                {
                    res = arr[i];
                    break;
                }
            }
        }
        return res;
    }
};