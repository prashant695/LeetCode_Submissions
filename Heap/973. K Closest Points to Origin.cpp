class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> q;
        vector<vector<int>> res;
        int x, y;

        for (int i = 0; i < points.size(); i++)
        {
            x = points[i][0], y = points[i][1];
            q.push({x * x + y * y, points[i]});
        }

        while (q.size() >= 1)
        {
            if (q.size() <= k)
                res.push_back(q.top().second);
            q.pop();
        }

        return res;
    }
};
