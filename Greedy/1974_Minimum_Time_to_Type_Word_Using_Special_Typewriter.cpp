class Solution {
public:
    int minTimeToType(string word) {
       word='a'+word;
       char x,y;
       int cnt=0;
       for(int i=1;word[i];i++) {
           if(word[i]==word[i-1]) cnt+=1;
           else {
               cnt++;
               x = word[i-1];
               y = word[i];
               if(x>y) swap(x,y);
               cnt+=min(y-x,abs(26-(y-x)));
           }
       }
        return cnt;
    }
};