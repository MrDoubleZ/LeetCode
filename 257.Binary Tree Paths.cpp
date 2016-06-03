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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res;
        dfs(root,res,"");
        return res;
    }
private:
    void dfs(TreeNode *root,vector<string> &res,string path)
    {
        if(!root)
            return;
        stringstream ss;
        if(path.size()>0)
            ss<<"->";
        ss<<root->val;
        string str;
        ss>>str;
        path+=str;
        if(!root->left&&!root->right)
        {
            res.push_back(path);
            return;
        }
        dfs(root->left,res,path);
        dfs(root->right,res,path);
        return;
    }
};
