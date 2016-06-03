class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> res(nums.size(),1);
        res[0]=1;
        int t=1;
        for(int i=1;i<nums.size();++i)
        {
            t*=nums[i-1];
            res[i]*=t;
        }
        t=1;
        for(int i=nums.size()-2;i>=0;--i)
        {
            t*=nums[i+1];
            res[i]*=t;
        }
        return res;
    }
};
