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
        bool dup=false;
        while(*p&&(*p)->next)
        {
            if((*p)->next->val==(*p)->val) 
            {
                *p=(*p)->next;
                dup=true;
            }
            else if(dup)
            {
                *p=(*p)->next;
                dup=false;
                continue;
            }
            else p=&((*p)->next);
        }
        if(dup)*p=(*p)->next;
        return sentinel.next;
    }
};

/*others' solution*/
/*class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **runner = &head;

        if(!head || !head->next)return head;

        while(*runner)
        {
            if((*runner)->next && (*runner)->next->val == (*runner)->val)
            {
                ListNode *temp = *runner;
                while(temp && (*runner)->val == temp->val)
                    temp = temp->next;

                *runner = temp;
            }
            else
                runner = &((*runner)->next);
        }

        return head;
    }
};*/
