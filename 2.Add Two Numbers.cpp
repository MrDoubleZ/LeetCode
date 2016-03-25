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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode(0);
        ListNode* tail=res;
        int a,b,c=0;
        while((l1!=NULL)||(l2!=NULL)||c!=0)
        {
            if (l1==NULL) a=0;
            else a=l1->val;
            if (l2==NULL) b=0;
            else b=l2->val;
            ListNode* perDigitRes=new ListNode((a+b+c)%10);
            c=(a+b+c)/10;
            tail->next=perDigitRes;
            tail=perDigitRes;
            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
        }
        return res->next;
    }
};