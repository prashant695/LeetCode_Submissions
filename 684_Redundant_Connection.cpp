class Solution
{
public:
    int parent[1001];
    long long rank[1001];
    int find(int u)
    {
        u = parent[u];
        while (u != parent[u])
        {
            u = parent[u];
        }
        return u;
    }
    int unionn(int u, int v)
    {
        int p1 = find(u);
        int p2 = find(v);

        if (p1 == p2)
        {
            return 1;
        }
        if (rank[p1] > rank[p2])
        {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        else
        {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        for (int i = 0; i < 1001; i++)
            parent[i] = i;
        for (int i = 0; i < 1001; i++)
            rank[i] = 1;
        vector<int> v;
        for (int i = 0; i < edges.size(); i++)
            if (unionn(edges[i][0], edges[i][1]))
                v = {edges[i][0], edges[i][1]};
        return v;
    }
};