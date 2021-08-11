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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *t = head, *tmp = head;
        while (t)
        {
            tmp = t;
            t = t->next;
            while (t && t->val == tmp->val)
                t = t->next;
            tmp->next = t;
            tmp = t;
        }
        return head;
    }
};