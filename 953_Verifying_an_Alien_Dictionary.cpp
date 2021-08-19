class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int m[26]={0};
        int a,b,cnt=0;
        string x,y;
        for(int i=0;order[i];i++) m[order[i]-'a']=i;
        
        for(int i=0;i<words.size()-1;i++)
        {
            x=words[i];
            y=words[i+1];
            a=0, b=0, cnt=0;
            while(a<words[i].size() && b<words[i+1].size())
            {
                if(m[words[i][a]-'a']<m[words[i+1][b]-'a']) {break;}
                else if(m[words[i][a]-'a']==m[words[i+1][b]-'a']){cnt++;}
                else if(m[words[i][a]-'a']>m[words[i+1][b]-'a']) {return false;}
                a++,b++;
            }
            if(cnt==words[i+1].size() && words[i]!=words[i+1]) return false;
        }
        return true;
    }
};