class Solution
{
public:
    static bool cmp(vector<int> p1, vector<int> p2)
    {
        return p1[0] - p2[0] < p1[1] - p2[1];
    }
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        int res = 0;
        sort(costs.begin(), costs.end(), cmp);
        // for(int i=0;i<n;i++) for(int j=0;j<=1;j++) cout<<costs[i][j]<<" ";
        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
                res += costs[i][0];
            else
                res += costs[i][1];
        }
        return res;
    }
};