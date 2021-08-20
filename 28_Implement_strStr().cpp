class Solution {
public:
    int strStr(string s, string needle) {
        if(needle=="") return 0;
        else if(s=="") return -1;
        else if(needle.size()>s.size()) return -1; 
        int x, j, pos;
        for(int i=0;i<s.size()-needle.size()+1;i++)
        {
            if(needle[0]==s[i])
            {
                x=i;
                j=i;
                pos=1;
                j++;
                while(pos<needle.size() && j<s.size())
                {
                    if(needle[pos]==s[j]) pos++,j++;
                    else break;
                }
                if(pos==needle.size()) return x;
            }
        }
        return -1;
    }
};