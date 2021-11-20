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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        int cnt = 0;
        ListNode *temp = head;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        if (k >= cnt)
            k = k % cnt;
        if (k == 0 || cnt == 1)
            return head;
        ListNode *slow = NULL;
        ListNode *fast = NULL;
        ListNode *temp2 = head;
        temp = head;
        cnt = 0;
        while (temp)
        {
            fast = temp;
            if (cnt >= k)
                slow = temp2, temp2 = temp2->next;
            temp = temp->next;
            cnt++;
        }
        temp2 = slow->next;
        slow->next = NULL;
        fast->next = head;
        head = temp2;
        return head;
    }
};