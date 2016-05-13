class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        int skip_rob=nums[0];
        int skip_skip=0;
        int rob_skip=0;
        for(size_t i=1;i<nums.size();++i)
        {
            int temp=skip_rob;
            skip_rob=nums[i]+max(skip_skip,rob_skip);
            skip_skip=rob_skip;
            rob_skip=temp;
        }
        return max(skip_rob,max(skip_skip,rob_skip));
    }
};

[1,2,4,6,3,5,7,8,4,2,9,2,8,4,2]//40