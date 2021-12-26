// Method-1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        while (headA)
        {
            ListNode *tmp = headB;
            while (tmp)
            {
                if (headA == tmp)
                    return headA;
                tmp = tmp->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};

// Method-2
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> m;
        while (headA)
        {
            m[headA]++;
            headA = headA->next;
        }
        while (headB)
        {
            if (m[headB])
                return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};
