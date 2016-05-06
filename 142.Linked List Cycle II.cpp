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
    ListNode *detectCycle(ListNode *head)
    {
        if(!head) return nullptr;
        ListNode *fst=head,*snd=head;
        while(snd->next&&snd->next->next)
        {
            fst=fst->next;
            snd=snd->next->next;
            if(fst==snd)
                break;
        }
        if(!(snd->next&&snd->next->next)) return nullptr;
        snd=head;
        while(fst!=snd)
        {
            fst=fst->next;
            snd=snd->next;
        }
        return fst;
    }
};