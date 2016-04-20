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
    void flatten(TreeNode* root)
    {
        vector<TreeNode*> stack;
        TreeNode *curr=root;
        TreeNode *prev=nullptr;
        while(curr||!stack.empty())
        {
            if(!curr)
            {
                curr=stack.back();
                stack.pop_back();
                prev->right=curr;
            }
            if(curr->right) 
            {
                stack.push_back(curr->right);
                curr->right=nullptr;
            }
            if(curr->left)
            {
                curr->right=curr->left;
                TreeNode *temp=curr->left;
                curr->left=nullptr;
                curr=temp;
            }
            else
            {
                prev=curr;
                curr=nullptr;
            }
        }
        return;
    }
};

/*others' solution*/
/*void flatten(TreeNode *root) {
    while (root) {
        if (root->left && root->right) {
            TreeNode* t = root->left;
            while (t->right)
                t = t->right;
            t->right = root->right;
        }

        if(root->left)
            root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
}*/