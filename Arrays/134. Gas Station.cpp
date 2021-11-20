class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int cur = 0, tot = 0, ans = 0;
        for (int i = 0; i < cost.size(); i++)
        {
            tot += gas[i] - cost[i];

            cur += gas[i] - cost[i];
            if (cur < 0)
                ans = i + 1, cur = 0;
        }
        if (tot < 0)
            return -1;
        return ans;
    }
};