class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int l = 1, h = arr.size() - 2, mid;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (arr[mid] > arr[mid + 1] and arr[mid] > arr[mid - 1])
                return mid;
            else if (arr[mid] > arr[mid + 1] and arr[mid] < arr[mid - 1])
                h = mid - 1;
            else
                l = mid + 1;
        }
        return 0;
    }
};