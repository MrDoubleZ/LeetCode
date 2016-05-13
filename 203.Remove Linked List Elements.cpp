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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode **p=&head;
        while(*p)
        {
            if((*p)->val==val)
                *p=(*p)->next;
            else
                p=&((*p)->next);
        }
        return head;
    }
};