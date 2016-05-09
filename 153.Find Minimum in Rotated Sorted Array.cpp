class Solution {
public:
    int findMin(vector<int>& nums)
    {
        if(nums[0]<nums[nums.size()-1]) return nums[0];
        //find pivot
        int beg=0;
        int end=nums.size()-1;
        int mid=beg+(end-beg)/2;
        while(beg<end)
        {
            if(nums[mid]>nums[end])
                beg=mid+1;
            else
                end=mid;
            mid=beg+(end-beg)/2;
        }
        int res=nums[mid];
        if(mid+1<nums.size())
            res=min(res,nums[mid+1]);
        if(mid-1>=0)
            res=min(res,nums[mid-1]);
        return res;
    }
};


//make a process
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        //if(nums[0]<nums[nums.size()-1]) return nums[0];
        //find pivot
        int beg=0;
        int end=nums.size()-1;
        int mid=0;
        while(beg<end)
        {
            mid=beg+(end-beg)/2;
            if(nums[mid]>nums[end])
                beg=mid+1;
            else
                end=mid;
        }
        //int res=nums[beg];
        //if(mid+1<nums.size())
        //    res=min(res,nums[mid+1]);
        //if(mid-1>=0)
        //    res=min(res,nums[mid-1]);
        return nums[beg];
    }
};