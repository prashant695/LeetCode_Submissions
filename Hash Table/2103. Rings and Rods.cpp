class Solution
{
public:
    int countPoints(string rings)
    {
        int cnt = 0;
        int r[10] = {0}, b[10] = {0}, g[10] = {0};

        for (int i = 0; i < rings.size(); i += 2)
        {
            if (rings[i] == 'R')
                r[rings[i + 1] - '0'] = 1;
            if (rings[i] == 'B')
                b[rings[i + 1] - '0'] = 1;
            if (rings[i] == 'G')
                g[rings[i + 1] - '0'] = 1;
        }
        for (int i = 0; i < 10; i++)
            if (r[i] and b[i] and g[i])
                cnt++;
        return cnt;
    }
};

