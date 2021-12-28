// Method-1
// storing length of linked list

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *tmp = head;
        int node = 0, cnt = 0;
        while (tmp)
        {
            node++;
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp)
        {
            cnt++;
            if (cnt == ceil((node + 1) / 2.0))
                return tmp;
            tmp = tmp->next;
        }
        return NULL;
    }
};

// Method-2
// Concept of even and odd

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *mid = head;
        int cnt = 0;
        while (head)
        {
            if (cnt & 1)
                mid = mid->next;
            cnt++;
            head = head->next;
        }
        return mid;
    }
};

// Method-3
// Hare and Turtle
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *turtle = head, *hare = head;
        while (hare and hare->next)
        {
            turtle = turtle->next;
            hare = hare->next->next;
        }
        return turtle;
    }
};