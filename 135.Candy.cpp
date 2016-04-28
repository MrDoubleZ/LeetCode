class Solution {
public:
    int candy(vector<int>& ratings)
    {
        if(ratings.size()<=1) return ratings.size();
        vector<int> nums(ratings.size(),1);
        int sum=0;
        for(size_t i=1;i<ratings.size();++i)
        {
            if(ratings[i]>ratings[i-1])
                nums[i]=nums[i-1]+1;
        }
        
        for(size_t i=ratings.size()-1;i>0;--i)
        {
            if(ratings[i-1]>ratings[i])
                nums[i-1]=max(nums[i]+1,nums[i-1]);
        }
        
        for(auto num:nums)
            sum+=num;
        return sum;
    }
};