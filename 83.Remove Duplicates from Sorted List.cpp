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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode sentinel(0);
        sentinel.next=head;
        ListNode **p=&sentinel.next;
        while(*p&&(*p)->next)
        {
            if((*p)->next->val==(*p)->val) *p=(*p)->next;
            else p=&((*p)->next);
        }
        return sentinel.next;
    }
};