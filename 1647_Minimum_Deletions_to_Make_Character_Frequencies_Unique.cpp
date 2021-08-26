class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>m,m2;
        int cnt=0,freq,temp;
        for(int i=0;i<s.size();i++) m[s[i]-'a']++;
        for(auto it: m) m2[it.second]++;
        for(int i=0;i<26;i++)
        {
            freq=m[i];
            temp=freq;
            if(freq>=1 && m2[freq]>=2)
            {
                cnt++;
                freq--;
                while(freq>=1 && m2[freq]!=0)  cnt++,freq--;
                m2[freq]++;
                m2[temp]--;
            }
        }
        return cnt;
    }
};