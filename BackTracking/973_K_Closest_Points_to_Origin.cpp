// Method_1
// using priority_queue<pair<int, vector<int>>> q;

class Solution
{
public:
    int dis(vector<int> v)
    {
        return ((v[0] * v[0]) + (v[1] * v[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> q;
        vector<vector<int>> res;
        for (int i = 0; i < points.size(); i++)
            q.push({dis(points[i]), points[i]});
        while (q.empty() == false)
        {
            if (q.size() <= k)
                res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

// Method_2 (faster)
// using vector<pair<int,vector<int>>>v;

class Solution {
public:
      int dist(vector<int> v)
    {
        return ((v[0] * v[0]) + (v[1] * v[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>>v;
        vector<vector<int>> res;
        for(int i=0;i<points.size();i++)
        {
            v.push_back({dist(points[i]),points[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++)
            res.push_back(v[i].second);
        return res;
    }
};