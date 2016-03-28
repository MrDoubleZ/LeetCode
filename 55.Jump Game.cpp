class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int curr=0;
        int max_reach=0;
        do
        {
            if(max_reach>=nums.size()-1) return true;
            if(max_reach<curr+nums[curr])
            {
                max_reach=curr+nums[curr];
                curr=max_reach;
            }
            else if(nums[curr]>0)++curr;
            else break;
        }while(curr<nums.size()-1);
        
        do
        {
            if(max_reach>=nums.size()-1) return true;
            if(max_reach<curr+nums[curr])
            {
                max_reach=curr+nums[curr];
                curr=max_reach;
            }
            else --curr;
        }while(curr>0);
        return false;
    }
};