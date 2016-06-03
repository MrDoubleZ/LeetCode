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
    bool isPalindrome(ListNode* head)
    {
        if(!head) return true;
        int len=0;
        ListNode *curr=head;
        while(curr)
        {
            curr=curr->next;
            ++len;
        }
        ListNode *head2;
        curr=head;
        for(int i=0;i<len/2;++i)
            curr=curr->next; 
        if(len%2==0)
            head2=curr;
        else
            head2=curr->next;
        curr=head;

        //reverse
        ListNode sentinel(0);
        sentinel.next=head;
        ListNode *prev=&sentinel;
        for(int i=0;i<len/2;++i)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
        }
        sentinel.next->next=nullptr;

        while(head2&&prev) 
        {
            if(head2->val!=prev->val)
                return false;
            head2=head2->next;
            prev=prev->next;
        }
        return true;
    }
};
