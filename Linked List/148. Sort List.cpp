// Method-1
// Using array

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
    ListNode *sortList(ListNode *head)
    {
        vector<int> v;
        int k = 0;
        ListNode *tmp = head;
        while (tmp)
        {
            v.push_back(tmp->val);
            tmp = tmp->next;
        }

        sort(v.begin(), v.end());
        tmp = head;
        while (tmp)
        {
            tmp->val = v[k++];
            tmp = tmp->next;
        }
        return head;
    }
};

// Method-2
// Bubble sort
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode *head2 = head, *tmp;
        while (head2)
        {
            tmp = head2->next;
            while (tmp)
            {
                if (tmp->val < head2->val)
                    swap(tmp->val, head2->val);

                tmp = tmp->next;
            }
            head2 = head2->next;
        }
        return head;
    }
};

// Method-3
// Using Merge sort
class Solution
{
public:
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *curr = new ListNode(0);
        ListNode *tmp = curr;
        while (head1 and head2)
        {
            if (head1->val < head2->val)
            {
                curr->next = head1;
                head1 = head1->next;
            }
            else
            {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        if (head1)
            curr->next = head1;
        if (head2)
            curr->next = head2;

        return tmp->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL or !head->next)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(fast));
    }
};
