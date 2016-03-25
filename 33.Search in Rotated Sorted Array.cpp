class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left=0;
        int right=nums.size()-1;
        int mid=left+(right-left)/2;
        while(left<right)
        {
            if(nums[mid]>nums[right])
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
            mid=left+(right-left)/2;
        }
        int pivot=mid;
        left=0;
        right=nums.size()-1;
        while(left<=right)
        {
            mid=(right+left)/2;
            int realmid=(mid+pivot)%nums.size();
            if(nums[realmid]>target)
            {
                right=mid-1;
            }
            else if(nums[realmid]<target)
            {
                left=mid+1;
            }
            else
            {
                return realmid;
            }  
        }
        return -1;
    }
};