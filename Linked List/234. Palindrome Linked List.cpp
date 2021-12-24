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

// Approach 1
// Store the content of linked list in array/vector
// Check for the array/vector to be a palindrome
// Just smart way to solve not the best
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s="";
        while(head){
            s+=head->val;
            head=head->next;
        }
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            else{i++;j--;}
        }
        return true;
    }
};

// Approach 2
// Using Tail recursion

class Solution
{
public:
    ListNode *tmp;
    bool ispali(ListNode *p)
    {
        if (p == NULL)
            return 1;
        if (!(ispali(p->next) and tmp->val == p->val))
            return 0;
        tmp = tmp->next;
        return 1;
    }
    bool isPalindrome(ListNode *head)
    {
        tmp = head;
        return ispali(head);
    }
};

// Approach 3
// Find the Middle of the linked list (Hare and Tortoise Approach)
// Reverse the second half of the linked list
// Check for the node values for the first half and second half to be equal


