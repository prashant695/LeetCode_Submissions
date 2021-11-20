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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> v;
        int n = 0, flg = 0, cnt = 0;
        ListNode *temp = head, *temp2, *h;
        while (temp)
        {
            n++;
            temp = temp->next;
        }
        int q = n / k;
        int rem = n % k;

        temp = head;
        while (temp)
        {
            h = temp;
            for (int i = 0; i < q - 1; i++)
            {
                if (temp->next)
                    temp = temp->next;
            }
            if (q >= 1 && flg < rem)
            {
                temp = temp->next;
                flg++;
            }

            if (temp == NULL)
                break;
            temp2 = temp->next;
            temp->next = NULL;
            v.push_back(h);
            temp = temp2;
        }
        while (v.size() < k)
        {
            v.push_back(NULL);
        }
        return v;
    }
};