class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        size_t new_length=nums.size();
        size_t curr=0;
        size_t next=1;
        while(next<new_length)
        {
            while(next<new_length&&nums[curr]==nums[next])
            {
                new_length-=1;
                nums.erase(nums.begin()+next);
            }
            curr+=1;
            next+=1;  
        }
        return new_length;
        
        /*others' solution*/
        /*int count = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1]) count++;
            else nums[i-count] = nums[i];
        }
        return nums.size()-count;*/
         
        
    }
};