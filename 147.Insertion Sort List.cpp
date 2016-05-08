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
    ListNode* insertionSortList(ListNode* head)
    {
        if(!head) return nullptr;
        ListNode sentinel(0);
        sentinel.next=head;
        ListNode *curr=head->next;
        ListNode *sorted_tail=head;
        while(curr)
        {
            ListNode *find_pos=sentinel.next;
            ListNode *prev_find_pos=&sentinel;
            while(find_pos->val<=curr->val&&prev_find_pos!=sorted_tail)
            {
                prev_find_pos=find_pos;
                find_pos=find_pos->next;
            }
            if(prev_find_pos!=sorted_tail)
            {
                prev_find_pos->next=curr;
                ListNode *temp=curr->next;
                curr->next=find_pos;
                curr=temp;
                sorted_tail->next=temp;
            }
            else
            {
                sorted_tail=curr;
                curr=curr->next;
            }
        }
        return sentinel.next;
    }
};

/*others solution*/
//剪枝
//class Solution { 
//public:
//    ListNode* insertionSortList(ListNode* head) {
//        ListNode* new_head = new ListNode(0);
//        new_head -> next = head;
//        ListNode* pre = new_head;
//        ListNode* cur = head;
//        while (cur) {
//            if (cur -> next && cur -> next -> val < cur -> val) {//很关键
//                while (pre -> next && pre -> next -> val < cur -> next -> val)
//                    pre = pre -> next;
//                /* Insert cur -> next after pre.*/
//                ListNode* temp = pre -> next;
//                pre -> next = cur -> next;
//                cur -> next = cur -> next -> next;
//                pre -> next -> next = temp;
//                /* Move pre back to new_head. */
//                pre = new_head;
//            }
//            else cur = cur -> next;
//        }
//        ListNode* res = new_head -> next;
//        delete new_head;
//        return res;
//    }
//};