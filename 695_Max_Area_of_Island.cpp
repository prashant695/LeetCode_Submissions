class Solution {
public:
    int cnt=0;
    int seen[51][51]={0};
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || seen[i][j]==1) 
            return 0;
        seen[i][j]=1;
        return 1+ dfs(grid,i+1,j)+ dfs(grid,i-1,j)+ dfs(grid,i,j+1)+ dfs(grid,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
               {
                    cnt = max(cnt, dfs(grid,i,j));
                }
            }
        }
        return cnt;
    }
};