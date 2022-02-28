class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {

        long long int l = 1, h = LONG_MAX, mid, cnt;
        // sort(time.begin(), time.end());
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            cnt = 0;
            for (auto x : time)
            {
                cnt += (mid / x);
                if (cnt > totalTrips)
                {
                    break;
                }
            }

            if (cnt >= totalTrips)
            {
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return l;
    }
};