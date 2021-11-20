class Solution
{
public:
    bool isPossibleDivide(vector<int> &hand, int groupSize)
    {
        map<int, int> m;
        for (int i = 0; i < hand.size(); i++)
            m[hand[i]]++;

        sort(hand.begin(), hand.end());

        for (int i = 0; i < hand.size(); i++)
        {
            if (m[hand[i]])
            {
                int sz = groupSize;
                int x = hand[i];
                while (sz--)
                {
                    if (m[x] == 0)
                        return 0;
                    else
                        m[x]--, x++;
                }
            }
        }
        return 1;
    }
};