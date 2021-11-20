class Solution {
public:
    vector<string>v;
    unordered_map<string,int>m;
    int fun(string s, int pos, string temp, string res)
    {
      if(pos>=s.size() and s==temp) {v.push_back(res);}  
      else if(pos>=s.size()) return 0;  
      
      string sam="";  
      for(int i=pos;i<s.size();i++)
      {
          sam+=s[i];
          if(m[sam]) { if(pos==0)
                  fun(s, i+1, temp+sam, sam); else
                  fun(s, i+1, temp+sam, res+' '+sam);
          }
      }
        return 0;
    }
     vector<string> wordBreak(string s, vector<string>& wordDict) {
       int pos=0;
       for(auto x: wordDict) m[x]++;
       fun(s,0,"", ""); 
       return v;
    }
};