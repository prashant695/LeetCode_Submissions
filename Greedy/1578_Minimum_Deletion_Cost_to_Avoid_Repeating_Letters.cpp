class Solution
{
public:
    int minCost(string s, vector<int> &cost)
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == s[i + 1])
            {
                cnt += min(cost[i], cost[i + 1]);
                cost[i] = max(cost[i], cost[i + 1]);
                cost[i + 1] = max(cost[i], cost[i + 1]);
            }
        }
        return cnt;
    }
};