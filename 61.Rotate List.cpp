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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head) return head;
        ListNode* front=head;
        ListNode* rear=head;
        int length=1;
        for(int i=0;i<k;++i)
        {
            if(front->next==nullptr)
            {
                front=head;
                for(int i=0;i<k%length;++i)
                {
                    front=front->next;
                }
                break;
            }
            else
            {
                front=front->next;
                ++length;
            }
        }
        while(front->next!=nullptr)
        {
            front=front->next;
            rear=rear->next;
        }
        front->next=head;
        head=rear->next;
        rear->next=nullptr;
        return head;
    }
};