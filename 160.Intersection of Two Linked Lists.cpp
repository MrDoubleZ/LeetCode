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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ha=headA,*hb=headB;
        while(ha&&hb)
        {
            ha=ha->next;
            hb=hb->next;
        }
        ListNode *cursor;
        if(!ha)//B is longer
        {
            cursor=hb;
            ha=headA;
            hb=headB;
            while(cursor)
            {
                cursor=cursor->next;
                hb=hb->next;
            }
            while(ha&&hb)
            {
                if(!ha&&ha==hb)
                    return ha;
                ha=ha->next;
                hb=hb->next;
            }
        }
        else//A is longer
        {
            cursor=ha;
            ha=headA;
            hb=headB;
            while(cursor)
            {
                cursor=cursor->next;
                ha=ha->next;
            }
            while(ha&&hb)
            {
                if(!ha&&ha==hb)
                    return ha;
                ha=ha->next;
                hb=hb->next;
            }
        }
        return nullptr;
        
    }
};

//shorter code
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    if (p1 == NULL || p2 == NULL) return NULL;
    while (p1 != NULL && p2 != NULL && p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;

        if (p1 == p2) return p1;

        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
    return p1;
}