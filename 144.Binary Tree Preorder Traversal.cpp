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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<TreeNode*> stack;
        vector<int> res;
        TreeNode *curr=root;
        while(curr||!stack.empty())
        {
            if(curr)
            {
                res.push_back(curr->val);
                if(curr->right)
                    stack.push_back(curr->right);
                curr=curr->left;
            }
            else
            {
                curr=stack.back();
                stack.pop_back();
            }
        }
        return res;
    }
};