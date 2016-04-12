/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int> nums;
        while(head)
        {
            nums.push_back(head->val);
            head=head->next;
        }
        return build(nums,0,nums.size());
    }
private:
    TreeNode* build(vector<int>& nums,int beg,int end)
    {
        if(beg>=end) return nullptr;
        int mid=beg+(end-beg)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=build(nums,beg,mid);
        root->right=build(nums,mid+1,end);
        return root;
    }
};