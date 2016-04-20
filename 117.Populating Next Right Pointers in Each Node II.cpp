/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root)
	{
		if (!root) return;
		TreeLinkNode *prev = root;
		TreeLinkNode *curr;
		while (prev)
		{
            if(!prev->left&&!prev->right)
            {
                prev=prev->next;
                continue;
            }
			curr = prev;
			TreeLinkNode *link_point = nullptr;
			if (curr->left)
			{
				link_point = curr->left;
				if (curr->right)
                {
                    link_point->next = curr->right;
                    link_point = link_point->next;
                }
			}
			else if(curr->right)
			{
                link_point = curr->right;
			}
			curr = curr->next;
			while (curr)
			{
				if (curr->left)
				{
					link_point->next = curr->left;
					link_point = link_point->next;
					if (curr->right)
                    {
                        link_point->next = curr->right;
                        link_point = link_point->next;
                    }
				}
				else if(curr->right)
				{
					link_point->next = curr->right;
					link_point = link_point->next;
				}
				curr = curr->next;
			}
			prev = prev->left ? prev->left : prev->right;
		}
	}
};