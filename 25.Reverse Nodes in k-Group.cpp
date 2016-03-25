class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		
		ListNode sentinel(0);
		sentinel.next = head;
		ListNode* curr = &sentinel;
		ListNode* next_section = nullptr;
		ListNode* prev_section = &sentinel;
		while (true)
		{
			for (size_t i = 0; i != k; ++i)
			{

				if (!curr)return sentinel.next;
				curr = curr->next;
			}
			if (!curr)return sentinel.next;
			next_section = curr->next;
			ListNode* curr_section_head= curr;
			ListNode* curr_section_tail= prev_section->next;
			/*reverse the linked list*/
			ListNode* p = curr_section_tail;
			ListNode* c = p->next;
			for (size_t i = 1; i != k; ++i)
			{
				if (c->next)
				{
					ListNode* r = c->next;
					c->next = p;
					p = c;
					c = r;
				}
				else
				{
					c->next = p;
				}
			}
			prev_section->next = curr_section_head;
			curr_section_tail->next = next_section;

			prev_section = curr_section_tail;
			curr = curr_section_tail;
		}

	}
};