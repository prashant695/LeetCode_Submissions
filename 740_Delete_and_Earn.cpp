class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		vector<int>v(10001,0);
        int dp[10001]={0};
        for(auto x:nums)
            v[x]+=x;
        
        dp[0]=v[0];
        dp[1]=max(v[0],v[1]);
        
        for(int i=2;i<10001;i++)
            dp[i]=max(dp[i-2]+v[i],dp[i-1]);
        
        return max(dp[10000],dp[9999]);
	}
};