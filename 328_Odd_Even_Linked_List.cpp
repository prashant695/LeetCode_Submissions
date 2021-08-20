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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode *t,*t2,*t22;
        t=head;
        t2=head->next;
        t22=head->next;
        while(t)
        {
            if(t->next==NULL){break;}
            else if(t->next->next==NULL) {break;}
            t->next=t2->next;
            t=t2->next;
            
            if(t!=NULL){
            t2->next=t->next;
            t2=t->next;
            }
        }
        t->next=t22;
        return head;
    }
};