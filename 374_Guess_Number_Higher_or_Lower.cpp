/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, h = n, mid;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            int x = guess(mid);
            if (x == 0)
                return mid;
            else if (x == -1)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};