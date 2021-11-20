class Solution {
public:
    int happy(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=pow(n%10,2);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int,int>m;
        m[n]=1;
        while(1)
        {
            n = happy(n);
            if(n==1) return true;
            else if(m[n]) return false;
            else m[n]=1;
        }
    }
};