class Solution {
public:
    int jump(vector<int>& nums)
    {   //if we choose max length each step, we will get to the end certainly
        //because wen can assume that wen can always reach the last index.
        if(nums.size()==0)return 0;
        int curr=0;
        int max_reach=curr+nums[curr];
        int res=0;
        int max_length=nums[curr];
        while(true)
        {
            if(max_reach>=nums.size()-1) return res+1;
            for(int i=curr+1;i!=curr+max_length+1;++i)
            {
                if(max_reach<i+nums[i])
                {
                    max_reach=i+nums[i];
                    curr=i;
                }
            }
            max_length=nums[curr];
            ++res;
        }
    }
};