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
    void reorderList(ListNode* head)
    {
        if(!head||!head->next) return;
        int cnt=0;
        ListNode *curr=head;
        while(curr)
        {
            ++cnt;
            curr=curr->next;
        }
        cnt/=2;
        curr=head;
        ListNode *snd=nullptr;
        while(cnt)
        {
            --cnt;
            curr=curr->next;
        }
        snd=curr->next;
        curr->next=nullptr;
        
        //reverse odd
        snd=reverse(snd);
        
        curr=head;
        ListNode *curr_next=curr->next;
        ListNode *snd_next;
        if(snd)
            snd_next=snd->next;
        while(curr&&snd)
        {
            curr->next=snd;
            snd->next=curr_next;
            curr=curr_next;
            snd=snd_next;
            if(curr_next)
                curr_next=curr_next->next;
            if(snd_next)
                snd_next=snd_next->next;
        }
        return;
       
    }
private:
    ListNode *reverse(ListNode *head)
    {
        if(!head) return nullptr;
        ListNode sentinel(0);
        sentinel.next=head;
        ListNode *prev=&sentinel;
        ListNode *curr=head;
        ListNode *next=head->next;
        while(curr)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            if(next)
                next=next->next;
        }
        head->next=nullptr;
        return prev;
    }
};

/*others solution*/
/*// O(N) time, O(1) space in total
void reorderList(ListNode *head) {
    if (!head || !head->next) return;

    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;

    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }

    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
}*/