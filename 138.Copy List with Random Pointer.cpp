/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        RandomListNode *dup_head=new RandomListNode(head->label);
        unordered_map<RandomListNode *,RandomListNode *> hashmap;
        hashmap[head]=dup_head;
        RandomListNode *curr=head;
        RandomListNode *dup_curr=dup_head;
        while(curr)
        {
            //if(hashmap.find(curr)==hashmap.end())
            //{
            //    RandomListNode *new_node=new RandomListNode(curr->label);
            //    hashmap[curr]=new_node;
            //}
            if(hashmap.find(curr->random)==hashmap.end())
            {
                RandomListNode *new_rand_node=new RandomListNode(curr->random->label);
                hashmap[curr->random]=new_rand_node;
            }
            if(hashmap.find(curr->next)==hashmap.end())
            {
                RandomListNode *new_next_node=new RandomListNode(curr->next->label);
                hashmap[curr->next]=new_next_node;
            }
            dup_curr->random=hashmap[curr->random];
            dup_curr->next=hashmap[curr->next];
            dup_curr=dup_curr->next;
            
            curr=curr->next;
        }
        return dup_head;
    }
};

/*others' solution*/
/*public RandomListNode copyRandomList(RandomListNode head) {
    RandomListNode iter = head, next;

    // First round: make copy of each node,
    // and link them together side-by-side in a single list.
    while (iter != null) {
        next = iter.next;

        RandomListNode copy = new RandomListNode(iter.label);
        iter.next = copy;
        copy.next = next;

        iter = next;
    }

    // Second round: assign random pointers for the copy nodes.
    iter = head;
    while (iter != null) {
        if (iter.random != null) {
            iter.next.random = iter.random.next;
        }
        iter = iter.next.next;
    }

    // Third round: restore the original list, and extract the copy list.
    iter = head;
    RandomListNode pseudoHead = new RandomListNode(0);
    RandomListNode copy, copyIter = pseudoHead;

    while (iter != null) {
        next = iter.next.next;

        // extract the copy
        copy = iter.next;
        copyIter.next = copy;
        copyIter = copy;

        // restore the original list
        iter.next = next;

        iter = next;
    }

    return pseudoHead.next;
}*/