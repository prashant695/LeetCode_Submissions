class Solution
{
public:
    vector<int> res, indegree;
    int cnt = 0;
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses, vector<int>());
        queue<int> q;
        indegree.resize(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        for (int i = 0; i < indegree.size(); i++)
            if (indegree[i] == 0)
                q.push(i);

        while (q.empty() == false)
        {
            cnt++;
            int node = q.front();
            q.pop();
            for (auto y : adj[node])
            {
                indegree[y]--;
                if (indegree[y] == 0)
                    q.push(y);
            }
        }
        if (cnt != numCourses)
            return 0;
        return 1;
    }
};
