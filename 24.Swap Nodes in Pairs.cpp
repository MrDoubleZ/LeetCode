class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        
       ListNode** p=&head;
       while(*p&&(*p)->next)
       {
           ListNode* n1=*p;
           *p=(*p)->next;
           p=&((*p)->next);
           n1->next=*p;
           *p=n1;
           p=&n1->next;
       }
       return head;
        
    }
    /*other's solution*/
    /*ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    cout<<head->val<<endl;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}*/
};