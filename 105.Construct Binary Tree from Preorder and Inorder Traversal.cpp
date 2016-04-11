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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        TreeNode *root=buildSubTree(preorder,inorder,0,preorder.size(),0,inorder.size());
        return root;
    }
private:
    TreeNode *buildSubTree(vector<int>& preorder, vector<int>& inorder,int pb,int pe,int ib,int ie)
    {
        if(ib>=ie) return nullptr;
        TreeNode* node=new TreeNode(preorder[pb]);
        int root_pos;
        for(int i=0;i!=ie;++i)
        {
            if(node->val==inorder[i])
            {
                root_pos=i;
                break;
            }
        }
        node->left=buildSubTree(preorder,inorder,pb+1,pb+root_pos-ib+1,ib,root_pos);
        node->right=buildSubTree(preorder,inorder,pb+root_pos-ib+1,pe,root_pos+1,ie);
        return node;
    }
};