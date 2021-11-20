class Solution
{
public:
    int check(int capacity, vector<int> &weights)
    {
        int cnt = 0, sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] > capacity)
                return INT_MAX;
            if (sum + weights[i] <= capacity)
            {
                sum += weights[i];
            }
            else
            {
                cnt++;
                sum = weights[i];
            }
        }
        return cnt + 1;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = 1, h = 1000000, mid, x;
        while (l < h)
        {
            mid = l + (h - l) / 2;
            x = check(mid, weights);
            if (x <= days)
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};