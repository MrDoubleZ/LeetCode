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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty())
        {
            vector<int> level;
            auto sz=queue.size();
            for(int i=0;i!=sz;++i)
            {
                
                if(!orientation)//left->right
                {
                    if(queue.front()->left)
                        queue.push_back(queue.front()->left);
                    if(queue.front()->right)
                        queue.push_back(queue.front()->right);
                    level.push_back(queue.front()->val);
                    queue.pop_front();
                }
                else//right->left
                {
                    if(queue.back()->right)
                        queue.push_front(queue.back()->right);
                    if(queue.back()->left)
                        queue.push_front(queue.back()->left);
                    level.push_back(queue.back()->val);
                    queue.pop_back();
                }
            }
            res.push_back(level);
            orientation^=0x01;
        }
        return res;
    }
private:
    unsigned char orientation=0x00;//0:left->right  1:right->left
};