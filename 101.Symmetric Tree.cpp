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
        return traverse(p->left,q->right)&&traverse(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root)
    {
        if(!root) return true;
        return traverse(root->left,root->right);
    }
};