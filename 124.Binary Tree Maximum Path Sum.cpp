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
    int maxPathSum(TreeNode* root)
    {
        int max=INT_MIN;
        findSingleMaxPath(root,max);
        return max;
        
    }
private:
    int findSingleMaxPath(TreeNode* root,int &max)
    {
        if(!root) return 0;
        int left=findSingleMaxPath(root->left,max);
        int right=findSingleMaxPath(root->right,max);
        if(left<0) left=0;
        if(right<0) right=0;
        if(left+right+root->val>max) max=left+right+root->val;
        return root->val+::max(left,right);
    }
};