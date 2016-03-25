/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class MinHeap
{
public:
	vector<ListNode*> array;
	int heap_size;
	void heap_decrease_key(size_t i, ListNode* key);

	inline size_t parent(size_t i)
	{
		return (i - 1) / 2;
	}
	inline size_t left(size_t i)
	{
		return 2 * i + 1;
	}
	inline size_t right(size_t i)
	{
		return (i + 1) * 2;
	}
	inline void display()
	{
		cout << "min heap:" << " ";
		for (int i = 0; i != heap_size; ++i)
		{
			cout << array[i]->val << " ";
		}
		cout << endl;
	}
	MinHeap(vector<ListNode*>&);
	void min_heapify(size_t i);
	void build_min_heap();
	ListNode* extract_min();
	void heap_insert(ListNode*);


};
MinHeap::MinHeap(vector<ListNode*>& ary)
{
	heap_size = ary.size();
	array = ary;
}

void MinHeap::min_heapify(size_t i)
{
	if (heap_size <= 0) return;
	size_t l = left(i);
	size_t r = right(i);
	int smallest = i;
	if (l <= heap_size - 1 && array[i]->val > array[l]->val) smallest = l;
	if (r <= heap_size - 1 && array[smallest]->val > array[r]->val) smallest = r;
	if (smallest != i)
	{
		ListNode* temp = array[i];
		array[i] = array[smallest];
		array[smallest] = temp;
		min_heapify(smallest);
	}
}

void MinHeap::build_min_heap()
{
	for (int i = heap_size / 2 - 1; i != -1; --i)
	{
		min_heapify(i);
	}
}

ListNode* MinHeap::extract_min()
{
	if (heap_size <= 0)
	{
		cout << "heap underflow" << endl;
		return nullptr;
	}
	
	ListNode* min = array[0];
	if (heap_size == 1)
	{
		heap_size -= 1;
		array.pop_back();
	}
	else
	{
		array[0] = array[heap_size - 1];
		heap_size -= 1;
		array.pop_back();
		min_heapify(0);
	}

	if (min->next) heap_insert(min->next);
	return min;

}
void MinHeap::heap_decrease_key(size_t i, ListNode* key)
{
	if (key->val > array[i]->val)
	{
		cout << "invalid key: it is larger than current key" << endl;
		return;
	}
	array[i] = key;
	
	int p = parent(i);
	
	while (i != 0 && array[p]->val > array[i]->val)
	{
		ListNode* temp = array[p];
		array[p] = array[i];
		array[i] = temp;
		i = p;
		p = parent(i);
	}
}
void MinHeap::heap_insert(ListNode* key)
{
	heap_size += 1;
	ListNode MAX(INT_MAX);
	ListNode* pmax = &MAX;
	array.push_back(pmax);
	heap_decrease_key(heap_size - 1, key);
}
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{

		ListNode head(0);
		ListNode* curr = &head;
		vector<ListNode*> min_heap;
		for(size_t i=0;i!=lists.size();++i)
		{
		    if(lists[i]) min_heap.push_back(lists[i]);
		}
		if (min_heap.size()==0) return nullptr;
		MinHeap mh(min_heap);
		mh.build_min_heap();
		while (mh.heap_size) 
		{
			curr->next = mh.extract_min();
			curr = curr->next;
		}
		return head.next;

	}
};