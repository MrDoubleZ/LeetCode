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
    void traverse(TreeNode* root)
    {
        if(!root) return;
        traverse(root->left);
        if(!first&&precessor->val>=root->val)//the first is always bigger than its precessor, 
            first=precessor;
        if(first&&precessor->val>=root->val)//while the second is smaller than its precessor.
            second=root;
        precessor=root;
        traverse(root->right);
        return;
    }
    void recoverTree(TreeNode* root)
    {
        traverse(root);
        swap(first->val,second->val);
        return;
    }
    Solution():first(nullptr),second(nullptr)
    {
        precessor=new TreeNode(INT_MIN);
    }
private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* precessor;
};