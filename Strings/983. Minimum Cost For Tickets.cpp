class Solution
{
public:
    map<int, int> m;
    int dp[366];
    int solve(vector<int> &costs, int curr_day)
    {
        if (curr_day > 365)
            return 0;
        if (m[curr_day] == 0)
            return solve(costs, curr_day + 1);
        if (dp[curr_day] != 0)
            return dp[curr_day];

        int a, b, c;
        a = costs[0] + solve(costs, curr_day + 1);
        b = costs[1] + solve(costs, curr_day + 7);
        c = costs[2] + solve(costs, curr_day + 30);

        return dp[curr_day] = min(a, min(b, c));
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        for (int i = 0; i < days.size(); i++)
            m[days[i]]++;

        memset(dp, 0, 366);

        return solve(costs, 1);
    }
};