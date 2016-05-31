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
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode*> parents;
        while(root->left)
        {
            parents.push(root);
            root=root->left;
        }
        for(int i=1;i<k;++i)
        {
            if(root->right)
            {
                root=root->right;
                while(root->left)
                {
                    parents.push(root);
                    root=root->left;
                }
            }
            else
            {
                root=parents.top();
                parents.pop();
            }
        }
        return root->val;
    }
};