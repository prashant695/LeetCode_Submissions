class Solution
{
public:
    string reorganizeString(string s)
    {
        int m[26] = {0};
        for (int i = 0; s[i]; i++)
            m[s[i] - 'a']++;
        priority_queue<pair<int, int>> q;

        s = "";
        for (int i = 0; i < 26; i++)
        {
            if (m[i])
            {
                q.push({m[i], i});
            }
        }
        while (q.size() > 1)
        {
            auto it1 = q.top();
            q.pop();
            auto it2 = q.top();
            q.pop();

            s += it1.second + 'a';
            s += it2.second + 'a';

            it1.first--;
            it2.first--;

            if (it1.first > 0)
                q.push(it1);
            if (it2.first > 0)
                q.push(it2);
        }
        if (q.size() >= 1)
        {
            if (q.top().first > 1)
                return "";
            s += q.top().second + 'a';
        }
        return s;
    }
};
