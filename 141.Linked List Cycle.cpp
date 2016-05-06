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
    bool hasCycle(ListNode *head)
    {
        set<ListNode*> s;
        while(head)
        {
            if(s.find(head)!=s.end())
                return true;
            s.insert(head);
            head=head->next;
        }
        return false;
    }
};

/*O(1) space*/
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fst=head,*snd=head;
        if(snd&&snd->next)
            snd=snd->next->next;
        else
            return false;
        while(fst)
        {
            if(fst==snd)
                return true;
            fst=fst->next;
            if(snd&&snd->next)
                snd=snd->next->next;
            else 
                return false;
        }
        return false;
    }
};