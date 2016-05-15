class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        return max(robRow(nums,0),robRow(nums,1));
    }
private:
    int robRow(vector<int>& nums,int start)
    {
        int sz=nums.size();
        int skip_rob=nums[start];
        int skip_skip=0;
        int rob_skip=0;
        for(int i=start+1;i<sz+start-1;++i)
        {
            int temp=skip_rob;
            skip_rob=nums[i]+max(skip_skip,rob_skip);
            skip_skip=rob_skip;
            rob_skip=temp;
        }
        return max(skip_rob,max(skip_skip,rob_skip));
    }
};
