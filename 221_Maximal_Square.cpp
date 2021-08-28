class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int cnt=0;
        int r=matrix.size();
        int c=matrix[0].size();
        int dp[r][c];
         for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                dp[i][j]=matrix[i][j]-'0';
            }
         }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(dp[i][j] && i && j)
                {
                    dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                }
                cnt=max(cnt,dp[i][j]);
            }
        }
        return cnt*cnt;
    }
};