/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root)
    {
        TreeNode *curr=root;
        while(curr)
        {
            stk.push(curr);
            curr=curr->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *res=stk.top();
        stk.pop();
        TreeNode *curr=res;
        if(curr->right)
        {
            curr=curr->right;
            while(curr)
            {
                stk.push(curr);
                curr=curr->left;
            }
        }
        return res->val;
    }
private:
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */