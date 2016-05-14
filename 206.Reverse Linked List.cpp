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
    ListNode* reverseList(ListNode* head)
    {
        if(!head) return head;
        ListNode sentinel(0);
        sentinel.next=head;
        ListNode *curr=head;
        ListNode *prev=&sentinel;
        while(curr)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        sentinel.next->next=nullptr;
        return prev;
    }
};