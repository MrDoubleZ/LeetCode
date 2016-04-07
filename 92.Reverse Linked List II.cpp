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
    void reverse(ListNode *head,ListNode *tail)
    {
        tail->next=nullptr;
        ListNode sentinel(0);
        sentinel.next=head;
        ListNode *prev=&sentinel;
        ListNode *curr=head;
        while(curr)
        {
            ListNode *temp=prev;
            prev=curr;
            curr=curr->next;
            prev->next=temp;
        }
    }
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode sentinel(0);
        sentinel.next=head;
        ListNode *curr=&sentinel;
        int i=0;
        for(;i<m-1;++i)
            curr=curr->next;
        ListNode *front=curr;
        ListNode *subhead=curr->next;
        for(;i<n;++i)
            curr=curr->next;
        ListNode *subtail=curr;
        ListNode *rear=curr->next;
        reverse(subhead,subtail);
        front->next=subtail;
        subhead->next=rear;
        return sentinel.next;
    }
};