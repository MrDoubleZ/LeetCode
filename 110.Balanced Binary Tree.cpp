/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //O(N^2)
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        if(!root) return true;
        if (abs(height(root->left)-height(root->right))>1)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
private:
    int height(TreeNode *root)
    {
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
};

//O(N)
/*class solution {
public:
int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;

        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }
};*/