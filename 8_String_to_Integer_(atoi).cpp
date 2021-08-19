class Solution {
  public:
    int myAtoi(string s) {
      int i = 0, neg = 0;
      long n = 0, t = pow(2, 31) - 1, t2 = -1 * pow(2, 31);
        
      while (s[i] == ' ') i++;
     
      if (s[i] == '-') neg = 1, i++;
      else if (s[i] == '+') i++;

      while (s[i] >= '0' && s[i] <= '9') {
        n = n * 10 + s[i] - '0';
        if (neg) {
          if (-1 * n <= t2) return t2;
        } else if (n >= t) return t;
        i++;
      }
        
      if (neg) n *= -1;
      return n;
    }
};