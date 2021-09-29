class Solution
{
public:
    string frequencySort(string s)
    {
        priority_queue<pair<int, char>> q;
        map<int, int> m;
        int freq, val;
        for (int i = 0; i < s.size(); i++)
            m[s[i] - 'a']++;

        for (auto it : m)
            q.push(make_pair(it.second, it.first + 'a'));
        s = "";
        while (q.empty() == false)
        {
            s += string(q.top().first, q.top().second);
            q.pop();
        }
        return s;
    }
};