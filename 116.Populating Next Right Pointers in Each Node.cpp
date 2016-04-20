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
		deque<TreeLinkNode*> level{ 1,root };
		while (!level.empty())
		{
			auto sz = level.size();
			for (int i = 0; i<sz; ++i)
			{
				TreeLinkNode *templ = level.front();
				level.pop_front();
				if (templ->left&&templ->right)
				{
					level.push_back(templ->left);
					level.push_back(templ->right);
				}
				if (i == sz - 1)
				{
					templ->next = nullptr;
					continue;
				}
				TreeLinkNode *tempr = level.front();
				templ->next = tempr;
				tempr->next = nullptr;
			}
		}
		return;
	}
};

class Solution {
 public:
	 void connect(TreeLinkNode *root)
	 {
	     if(!root) return;
		 fixSubTree(root);
	 }
 private:
	 void fixSubTree(TreeLinkNode *root)
	 {
		 if (!root->left&&!root->right) return;
		 fixSubTree(root->left);
		 fixSubTree(root->right);
		 TreeLinkNode *l = root->left;
		 TreeLinkNode *r = root->right;
		 while (l&&r)
		 {
			 l->next = r;
			 l = l->right;
			 r = r->left;
		 }
	 }
 };
 
class Solution {
public:
	void connect(TreeLinkNode *root)
	{
        if(!root) return;
        TreeLinkNode *curr=root;
        TreeLinkNode *prev=root;
        while(prev->left)
        {
            curr=prev;
            while(curr)
            {
                curr->left->next=curr->right;
                if(curr->next) curr->right->next = curr->next->left;
                curr=curr->next;
            }
            prev=prev->left;
        }
        return;
	}
};