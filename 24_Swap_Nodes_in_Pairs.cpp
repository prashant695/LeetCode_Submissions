class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(0), *dummy2;
        dummy->next = head;
        dummy2 = dummy;
        ListNode *temp, *temp_prev;
        while (dummy->next != NULL && dummy->next->next != NULL)
        {
            temp = dummy->next->next;
            temp_prev = dummy->next;
            dummy->next = temp;
            temp_prev->next = temp->next;
            temp->next = temp_prev;
            dummy = temp_prev;
        }
        return dummy2->next;
    }
};
