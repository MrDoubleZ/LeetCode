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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        //if (n<=1) return NULL;
        queue<ListNode*> q;
        ListNode sentinel=ListNode(0);
        sentinel.next=head;
        ListNode* curr=&sentinel;
        while(curr!=NULL)
        {
            if(q.size()>=n+1) q.pop();
            q.push(curr);
            curr=curr->next;
        }
        ListNode* prev=q.front();
        q.pop();
        ListNode* target=q.front();
        prev->next=target->next;
        return sentinel.next;
    }
};