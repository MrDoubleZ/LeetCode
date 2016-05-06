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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<TreeNode*> stack;
        vector<int> res;
        TreeNode *curr=root;
        TreeNode *prev=root;
        while(curr||!stack.empty())
        {
            if(curr)
            {
                if(!curr->left&&!curr->right)
                {
                    res.push_back(curr->val);
                    prev=curr;
                    curr=nullptr;
                }
                else if(curr->left==prev)
                {
                    if(curr->right)
                    {
                        stack.push_back(curr);
                        prev=curr;
                        curr=curr->right;
                    }
                    else
                    {
                        res.push_back(curr->val);
                        prev=curr;
                        curr=nullptr;
                    }
                    
                }
                else if(curr->right==prev)
                {
                    res.push_back(curr->val);
                    prev=curr;
                    curr=nullptr;
                }
                else
                {
                    stack.push_back(curr);
                    prev=curr;
                    curr=curr->left?curr->left:curr->right;
                }  
            }
            else
            {
                curr=stack.back();
                stack.pop_back();
            }
        }
        return res;
    }
};


/*two stacks*/
/*#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
         stack<TreeNode*> s,out;
        vector<int> vec;
        if(root == NULL)
            return vec;

        s.push(root);
        while(!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            out.push(node);
            if(node->left)
                s.push(node->left);
            if(node->right)
                s.push(node->right);
        }

        while(!out.empty())
        {
            vec.push_back(out.top()->val);
            out.pop();
        }
        return vec;
    }
};*/