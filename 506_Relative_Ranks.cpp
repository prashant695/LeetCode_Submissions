class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        priority_queue<pair<int, int>> q;
        int n = score.size();
        int flg = 0, s = 4;
        vector<string> v(n, "");
        for (int i = 0; i < n; i++)
            q.push({score[i], i});
        while (q.empty() == false)
        {
            flg++;
            if (flg == 1)
                v[q.top().second] = "Gold Medal";
            else if (flg == 2)
                v[q.top().second] = "Silver Medal";
            else if (flg == 3)
                v[q.top().second] = "Bronze Medal";
            else
                v[q.top().second] = to_string(s), s++;
            q.pop();
        }
        return v;
    }
};