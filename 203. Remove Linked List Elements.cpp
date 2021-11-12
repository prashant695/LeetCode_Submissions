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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return nullptr;
        while (head and head->val == val)
            head = head->next;
        ListNode *p = head, *x = p;
        if (p == nullptr)
            return nullptr;
        p = p->next;
        while (p)
        {
            if (p->val != val)
                x->next = p, x = p;
            p = p->next;
        }
        x->next = NULL;
        return head;
    }
};
