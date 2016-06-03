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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
       TreeNode *little=(p->val<q->val)?p:q;
       TreeNode *big=(p->val<q->val)?q:p;
       if(big->val<root->val)
           return lowestCommonAncestor(root->left,p,q);
       else if(little->val>root->val)
           return lowestCommonAncestor(root->right,p,q);
       else
           return root;
    }
};
