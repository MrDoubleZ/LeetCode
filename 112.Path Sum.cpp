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
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(!root) return false;
        if(sum-root->val==0&&!root->left&&!root->right) return true;
        else if(!root->left&&!root->right) return false;//reach leaf node and sum!=0, this path is invalid
        if(!root->left) return hasPathSum(root->right,sum-root->val);
        else if(!root->right) return hasPathSum(root->left,sum-root->val);
        else return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);   
    }
};