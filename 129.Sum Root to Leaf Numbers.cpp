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
    int sumNumbers(TreeNode* root)
    {
        return calc(root,0);
    }
private:
    int calc(TreeNode *root,int sum)
    {
        if(!root) return 0;
        sum*=10;
        sum+=root->val;
        if(root->left&&root->right)
            return calc(root->left,sum)+calc(root->right,sum);
        else if(root->left)
            return calc(root->left,sum);
        else if(root->right)
            return calc(root->right,sum);
        else return sum;
    }
};