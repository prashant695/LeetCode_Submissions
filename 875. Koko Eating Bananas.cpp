class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int t)
    {
        int l = 1, h = *max_element(piles.begin(), piles.end()), speed;
        while (l <= h)
        {
            speed = l + (h - l) / 2;
            int time = 0;
            for (int i = 0; i < piles.size(); i++)
            {
                time += ceil(piles[i] / (speed * 1.0));
            }

            if (time <= t)
                h = speed - 1;
            if (time > t)
                l = speed + 1;
        }
        return l;
    }
};