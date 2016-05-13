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
    vector<int> rightSideView(TreeNode* root)
    {
        //bfs
        deque<TreeNode*> level;
        level.push_back(nullptr);
        vector<int> res;
        TreeNode *curr=root;
        while(curr)
        {
            if(curr)
            {
                if(curr->left)
                    level.push_back(curr->left);
                if(curr->right)
                    level.push_back(curr->right);
            }
            if(!level.front())
            {
                res.push_back(curr->val);
                level.pop_front();
                if(level.empty())
                    break;
                level.push_back(nullptr);
            }
            curr=level.front();
            level.pop_front();
        }
        return res; 
    }
};
/*others solution*/
//dfs
class Solution {
public:
    void dfs(TreeNode* root, int lv, vector<int> &res){
        if(!root)   return;
        if(lv>=res.size()) res.push_back(root->val);
        dfs(root->right,lv+1,res);
        dfs(root->left,lv+1,res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};
