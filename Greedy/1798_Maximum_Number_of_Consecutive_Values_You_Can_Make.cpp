class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        map<int, int> m;
        for (int i = 0; i < coins.size(); i++)
            m[coins[i]]++;

        int res = 0;
        for (auto it : m)
        {
            if (res + 1 >= it.first)
            {
                res += (it.first * it.second);
            }
            else
                return res + 1;
        }
        return res + 1;
    }
};