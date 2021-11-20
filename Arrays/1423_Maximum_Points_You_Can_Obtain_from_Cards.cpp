class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size(), res = -1;
        vector<int> pre_sum;
        pre_sum.push_back(0);
        pre_sum.push_back(cardPoints[0]);
        for (int i = 1; i < n; i++)
            pre_sum.push_back(pre_sum[i] + cardPoints[i]);

        for (int i = n - k, j = 0; i <= n; i++, j++)
        {
            res = max(res, pre_sum[n] - pre_sum[i] + pre_sum[j]);
        }
        return res;
    }
};