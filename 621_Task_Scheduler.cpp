class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> m;
    for (int i = 0; i < tasks.size(); i++)
      m[tasks[i]]++;

    priority_queue<int> q;
    vector<int> v;
    for (auto it : m)
      q.push(it.second);
   
    int cnt = 0, cnt2 = 0;

    while (1) {
      int n2 = n + 1;
      v.clear();
      while (n2--) {
        if (q.empty() == false) {
          int x = q.top();
          q.pop();
          cnt++;
          cnt2++;
          if (cnt2 == tasks.size())
            return cnt;

          if (x >= 2)
            v.push_back(x - 1);
        } else
          cnt++;
      }
      for (int i = 0; i < v.size(); i++)
        q.push(v[i]);
    }
  }
};

// Method_2
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        
        int ans = (count-1)*(n+1);
        for(auto e : mp) if(e.second == count) ans++;
        return max((int)tasks.size(), ans);
    }
};