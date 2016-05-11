class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int major;
        int count=0;
        for(size_t i=0;i<nums.size();++i)
        {
            if(count==0)
            {
                major=nums[i];
                ++count;
            }
            else
            {
                if(major==nums[i])
                    ++count;
                else
                    --count;
            }
        }
        return major;
    }
};
