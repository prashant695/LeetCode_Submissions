class Solution
{
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles)
    {
        map<pair<long long, long long>, long long> m;
        long long x, a, b;
        long long cnt = 0;
        for (int i = 0; i < rectangles.size(); i++)
        {
            x = __gcd(rectangles[i][0], rectangles[i][1]);
            a = rectangles[i][0] / x;
            b = rectangles[i][1] / x;

            m[{a, b}]++;
        }

        for (auto it : m)
        {
            x = it.second;
            x--;
            cnt += ((x * (x + 1))) / 2;
        }
        return cnt;
    }
};