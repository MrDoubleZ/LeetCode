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
    void findPath(TreeNode* root, int sum,vector<int> &path,vector<vector<int>> &res)
    {
        if(!root) return;
        if(sum-root->val==0&&!root->left&&!root->right) 
        {
            res.push_back(path);
            return;
        }
        else if(!root->left&&!root->right) return;//reach leaf node and sum!=0, this path is invalid
        if(!root->left) 
        {
            path.push_back(root->val);
            findPath(root->right,sum-root->val,path,res);
            path.pop_back();
        }
        else if(!root->right) 
        {
            path.push_back(root->val);
            findPath(root->left,sum-root->val,path,res);
            path.pop_back();
        }
        else 
        {
            path.push_back(root->val);
            findPath(root->right,sum-root->val,path,res);
            findPath(root->left,sum-root->val,path,res);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> res;
        vector<int> path;
        findPath(root,sum,path,res);
        return res;
    }
};
/*others' solution*/
//same idea, just more clear
/*class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};*/