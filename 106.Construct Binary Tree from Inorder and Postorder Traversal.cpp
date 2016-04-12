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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return buildSubTree(inorder,postorder,0,inorder.size(),0,postorder.size());
    }
private:
    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder,int ib,int ie,int pb,int pe)
    {
        if(ib>=ie) return nullptr;
        TreeNode *root=new TreeNode(postorder[pe-1]);
        int root_pos;
        for(int i=0;i!=ie;++i)
        {
            if(root->val==inorder[i])
            {
                root_pos=i;
                break;
            }
        }
        root->left=buildSubTree(inorder,postorder,ib,root_pos,pb,pb+root_pos-ib);
        root->right=buildSubTree(inorder,postorder,root_pos+1,ie,pe-1-(ie-root_pos-1),pe-1);
        return root;
    }
};