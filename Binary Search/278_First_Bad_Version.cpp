// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 0, h = n;
        while (l < h)
        {
            int mid = l + (h - l) / 2;
            int x = isBadVersion(mid);
            if (x)
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};