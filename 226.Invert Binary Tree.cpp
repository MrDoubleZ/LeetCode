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
    TreeNode* invertTree(TreeNode* root)
    {
       if(!root) return nullptr;
       TreeNode *inv=new TreeNode(root->val);
       invert(root,inv);
       return inv;
    }
private:
    void invert(TreeNode *root,TreeNode *inv)
    {
        if(root->left)
        {
            inv->right=new TreeNode(root->left->val);
            invert(root->left,inv->right);
        }
        if(root->right)
        {
            inv->left=new TreeNode(root->right->val);
            invert(root->right,inv->left);
        }
        return;
    }
};
