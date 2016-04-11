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
    bool _isValid(TreeNode* root,TreeNode* biggest,TreeNode* smallest)
    {
        if(!root) return true;
        if((biggest&&root->val>=biggest->val)||(smallest&&root->val<=smallest->val)) return false;
        return _isValid(root->left,root,smallest)&&_isValid(root->right,biggest,root);
    }
    bool isValidBST(TreeNode* root)
    {
        return _isValid(root,NULL,NULL);
    }
};