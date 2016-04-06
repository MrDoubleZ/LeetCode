/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode sentinel(0);
        sentinel.next=head;
        
        ListNode sentinel1(1);
        ListNode *less=&sentinel1;
        
        ListNode *curr=head;
        ListNode *prev=&sentinel;
        while(curr)
        {
            ListNode *temp=curr->next;
            if(curr->val<x)
            {
                prev->next=curr->next;
                less->next=curr;
                less=less->next;
            }
            else prev=prev->next;
            curr=temp;
        }
        less->next=sentinel.next;
        return sentinel1.next;
    }
};