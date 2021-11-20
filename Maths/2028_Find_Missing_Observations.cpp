class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        long long sum = 0;
        for (int i = 0; i < rolls.size(); i++)
        {
            sum += rolls[i];
        }
        long long to = (n + rolls.size()) * mean;
        to = to - sum;

        vector<int> v;
        int q = to / n;
        int rem = to % n;

        for (int i = 0; i < n; i++)
            v.push_back(q);
        for (int i = 0; i < rem; i++)
            v[i] += 1;

        for (int i = 0; i < v.size(); i++)
            if (v[i] > 6 or v[i] <= 0)
                return {};
        return v;
    }
};