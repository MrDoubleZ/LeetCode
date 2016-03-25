class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        size_t curr=0;
        size_t new_length=nums.size();
        while(curr<new_length)
        {
            if(nums[curr]==val)
            {
                new_length-=1;
                nums[curr]=nums[new_length];
                continue;
            }
            curr+=1;
        }
        return new_length;
    }
};