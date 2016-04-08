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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<TreeNode*> stack;
        vector<int> res;
        TreeNode *curr=root;
        while(curr||!stack.empty())
        {
            if(!curr)
            {
                curr=stack.back();
                stack.pop_back();
                res.push_back(curr->val);
                curr=curr->right;
                continue;
            }
            stack.push_back(curr);
            curr=curr->left;
        }
        return res;
    }
};