class Solution {
public:
    int res=0;
    unordered_map<string,int>m;
    int dp[301];
    int fun(string s, int pos, string temp)
    {
      if(dp[pos]!=-1) return dp[pos];  
      if(pos>=s.size() and s==temp) {res=1;return 1;}  
      else if(pos>=s.size()) return 0;  
      
      string sam="";    
      for(int i=pos;i<s.size();i++)
      {
          sam+=s[i];
          if(m[sam]) dp[pos]=fun(s, i+1, temp+sam);
      }
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       int pos=0;
       for(auto x: wordDict) m[x]++;
       memset(dp,-1,sizeof(dp)); 
       fun(s,0,""); 
       return res;
    }
};