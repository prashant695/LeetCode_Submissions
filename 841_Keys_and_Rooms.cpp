class Solution
{
public:
    int vis[1001] = {0};
    void dfs(vector<vector<int>> &rooms, int curr_room, vector<vector<int>> &adj)
    {
        if (vis[curr_room] == 1)
            return;
        vis[curr_room] = 1;
        for (auto x : adj[curr_room])
            dfs(rooms, x, adj);
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<vector<int>> adj;
        for (int i = 0; i < rooms.size(); i++)
            adj.push_back(rooms[i]);
        dfs(rooms, 0, adj);

        for (int i = 0; i < rooms.size(); i++)
            if (vis[i] != 1)
                return false;
        return true;
    }
};