//O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int min_beg=0;
        int min_length=INT_MAX;
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            while(sum>=s)
            {
                min_length=min(min_length,i-min_beg+1);
                sum-=nums[min_beg++];
            }
        }
        return min_length==INT_MAX?0:min_length;
    }
};
