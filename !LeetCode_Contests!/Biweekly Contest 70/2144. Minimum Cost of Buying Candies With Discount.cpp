class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        sort(cost.begin(), cost.end());

        int s = 0, f = 0;

        for (int i = cost.size() - 1; i >= 0; i--)
        {
            if (f % 3 == 2)
            {
            }
            else
                s += cost[i];

            f++;
        }

        return s;
    }
};