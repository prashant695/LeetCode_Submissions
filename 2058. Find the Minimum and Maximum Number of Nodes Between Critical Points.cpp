/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *prev = head, *p = head;
        int i = 0, n = 0;
        vector<int> v, res, v2;
        while (p)
        {
            v.push_back(p->val);
            p = p->next;
            n++;
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (v[i] > v[i - 1] and v[i] > v[i + 1])
                v2.push_back(i);
            if (v[i] < v[i - 1] and v[i] < v[i + 1])
                v2.push_back(i);
        }
        cout << v2.size() << endl;

        if (v2.size() >= 2)
        {
            int ma = v2[v2.size() - 1] - v2[0];
            int mi = INT_MAX;

            for (int i = 1; i < v2.size(); i++)
            {
                mi = min(mi, v2[i] - v2[i - 1]);
            }
            return {mi, ma};
        }

        return {-1, -1};
    }
};