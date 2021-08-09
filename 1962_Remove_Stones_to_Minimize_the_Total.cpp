class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int x;
        priority_queue<int> q;
        for (int i = 0; i < piles.size(); i++)
            q.push(piles[i]);
        for (int i = 0; i < k; i++)
        {
            x = q.top();
            q.pop();
            q.push(x - x / 2);
        }
        x = 0;
        while (q.empty() == false)
        {
            x += q.top();
            q.pop();
        }
        return x;
    }
};