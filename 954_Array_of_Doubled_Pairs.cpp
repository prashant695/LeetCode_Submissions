class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        map<int, int> m;
        sort(arr.begin(), arr.end());
        int cnt_z = 0;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == 0)
                cnt_z++;
            else
                m[arr[i]]++;
        if (cnt_z % 2 == 1)
            return false;
        for (int i = 0; i < arr.size(); i++)
        {
            if (m[arr[i]] && m[2 * arr[i]] && arr[i] != 0)
            {
                m[arr[i]]--;
                m[2 * arr[i]]--;
            }
        }
        for (auto it : m)
        {
            if (it.second)
                return false;
        }
        return true;
    }
};