class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        int m[26] = {0};
        int maxx = -1;
        char res = keysPressed[0];
        m[keysPressed[0] - 'a'] = releaseTimes[0];

        for (int i = 1; i < keysPressed.size(); i++)
        {
            m[keysPressed[i] - 'a'] += releaseTimes[i] - releaseTimes[i - 1];
        }

        for (int i = 0; i < 26; i++)
        {

            if (m[i] >= maxx)
            {
                maxx = m[i];
                res = i + 'a';
            }
        }
        return res;
    }
};