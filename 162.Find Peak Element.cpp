class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int beg=0,end=nums.size()-1,mid=0,mid2=0;
        while(beg<end)
        {
            mid=beg+(end-beg)/2;
            mid2=mid+1;
            if(nums[mid]<nums[mid2])
                beg=mid2;
            else
                end=mid;
        }
        return beg;
    }
};