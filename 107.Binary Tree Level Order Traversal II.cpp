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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if(!root) return vector<vector<int>>();
        deque<vector<int>> res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        //TreeNode* curr=root;
        while(!queue.empty())
        {
            vector<int> level;
            auto sz=queue.size();
            for(int i=0;i!=sz;++i)
            {
                if(queue.front()->left)
                    queue.push_back(queue.front()->left);
                if(queue.front()->right)
                    queue.push_back(queue.front()->right);
                level.push_back(queue.front()->val);
                queue.pop_front();
            }
            res.push_front(level);
        }
        return {res.begin(),res.end()};
    }
};