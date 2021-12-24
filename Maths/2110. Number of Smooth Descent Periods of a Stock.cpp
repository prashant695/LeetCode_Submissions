class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long cnt = 0, cnt2 = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - prices[i - 1] == -1)
                cnt2++;
            else
                cnt += (cnt2 * (cnt2 + 1)) / 2, cnt2 = 0;
        }
        if (cnt2 > 0)
            cnt += (cnt2 * (cnt2 + 1)) / 2;

        return cnt + prices.size();
    }
};