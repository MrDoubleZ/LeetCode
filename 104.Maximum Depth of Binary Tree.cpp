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
    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;
        if(!root->left) return maxDepth(root->right)+1;
        if(!root->right) return maxDepth(root->left)+1;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
/*others' solution*/
//dfs
/*class Solution {
public:
    int maxDepth(TreeNode *root)
    {
        return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};*/
//bfs
/*class Solution {
public:
    int maxDepth(TreeNode *root)
    {
        if(root == NULL)
            return 0;
    
        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            ++ res;
            for(int i = 0, n = q.size(); i < n; ++ i)
            {
                TreeNode *p = q.front();
                q.pop();
    
                if(p -> left != NULL)
                    q.push(p -> left);
                if(p -> right != NULL)
                    q.push(p -> right);
            }
        }
    
        return res;
    }
};*/