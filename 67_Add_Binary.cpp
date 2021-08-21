class Solution {
public:
    string addBinary(string s, string s2) {
        string res=""; 
        if(s.size()<s2.size())
        {
            int d=s2.size()-s.size();
            for(int i=1;i<=d;i++) s='0'+s;
        }
        else if(s.size()>s2.size())
        {
            int d=s.size()-s2.size();
            for(int i=1;i<=d;i++) s2='0'+ s2;
        } 
        int carry=0,cnt=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            cnt=0;
            if(s[i]=='1') cnt++;
            if(s2[i]=='1') cnt++;
            if(carry) cnt++;
            if(cnt>=2) carry=1;
            else carry=0;
            if(cnt%2==1) res+='1';
            else if(cnt==2) res+='0';
            else if(s[i]=='0' && s2[i]=='0' && carry==0) 
                res+='0';
            else 
                res+='1';
        }
        if(carry) res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
};