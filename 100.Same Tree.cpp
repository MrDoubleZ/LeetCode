/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool traverse(TreeNode* p,TreeNode* q)//pre-order
    {
        if(!p&&!q) return true;
        if(!(p&&q&&p->val==q->val)) return false;
        return traverse(p->left,q->left)&&traverse(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        return traverse(p,q);
    }
};