class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int cnt=0;
        for(int i=0;i<nums.size()&&cnt<nums.size();++i)
        {
            while(nums[i]!=nums.size()&&nums[i]!=i&&cnt<nums.size())
            {
                std::swap(nums[nums[i]],nums[i]);
                ++cnt;
            }
        }
        for(int i=0;i<nums.size();++i)
            if(nums[i]!=i)
                return i;
        return nums.size();
    }
};
