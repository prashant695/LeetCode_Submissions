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
    int res = 0;
    ListNode *tmp;
    void fun(ListNode *head)
    {
        if (head == NULL)
        {
            return;
        }
        fun(head->next);
        res = max(res, tmp->val + head->val);
        tmp = tmp->next;
    }
    int pairSum(ListNode *head)
    {
        tmp = head;
        fun(head);
        return res;
    }
};