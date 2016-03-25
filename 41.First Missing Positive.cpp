class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        for (int i=0;i!=nums.size();++i)
        {
            if(i==nums[i]-1) continue;
            int x=nums[i];
            while(x>0&&x<=nums.size()&&x!=nums[x-1])
            {
                swap(x,nums[x-1]);
            }
        }
        for (int i=0;i!=nums.size();++i)
        {
            if(i!=nums[i]-1)return i+1;
        }
        return nums.size()+1;
    }
};