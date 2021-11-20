class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int cnt=0;
        int r=grid.size(),c=grid[0].size(),time=-1;
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(grid[i][j]==1) cnt++;
        if(cnt==0) return 0;
        int seen[r][c];
        memset(seen,0,sizeof(seen));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++) if(grid[i][j]==2) {q.push({i,j});}
        }
        while(q.empty()==false)
        {
            int qu=q.size();
            time++;
            for(int x=0;x<qu;x++)
            {
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(seen[i][j]!=3)
                {
                    if(i<r-1 && grid[i+1][j]==1 && seen[i+1][j]!=3) q.push({i+1,j}),grid[i+1][j]=2;
                    if(i>=1 && grid[i-1][j]==1 && seen[i-1][j]!=3) q.push({i-1,j}),grid[i-1][j]=2;
                    if(j<c-1 && grid[i][j+1]==1 && seen[i][j+1]!=3) q.push({i,j+1}),grid[i][j+1]=2;
                    if(j>=1 && grid[i][j-1]==1 && seen[i][j-1]!=3) q.push({i,j-1}),grid[i][j-1]=2;
                    seen[i][j]=3,grid[i][j]=2;
                }
            }
        }
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(grid[i][j]==1 && seen[i][j]==0) return -1;
        return time;
    }
};