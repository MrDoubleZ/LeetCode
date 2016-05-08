/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//maybe non-recursive merge sort is better
class Solution {
public:
	ListNode* sortList(ListNode* head)
	{
		return mergeSort(head);
	}
private:
	ListNode* mergeSort(ListNode *head)
	{
		if (!head) return nullptr;
		//find middle
		ListNode *walker = head;//walker is the middle
		ListNode *runner = head;
		while (runner&&runner->next&&runner->next->next)
		{
			walker = walker->next;
			runner = runner->next->next;
		}
		ListNode *right = walker->next;
		if (!right) return head;
		walker->next = nullptr;
		ListNode *left = mergeSort(head);
		right = mergeSort(right);

		//merge
		ListNode sentinel(0);
		ListNode **tail = &sentinel.next;
		while (left || right)
		{
			if ((left&&right&&left->val<right->val) || (left&&!right))
			{
				*tail = left;
				left = left->next;
			}
			else if ((left&&right&&left->val >= right->val) || (right&&!left))
			{
				*tail = right;
				right = right->next;
			}
			tail = &((*tail)->next);
		}
		return sentinel.next;
	}
};