class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left=0;
        int right=nums.size()-1;
        if(nums[left]>target) return 0;
        if(nums[right]<target) return nums.size();
        int mid;
        while(left<right)
        {
            mid=(left+right)/2;
            if(nums[mid]>target)
            {
                right=mid;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            else return mid;
        }
        return left;
    }
};
/*others' solution*/
/*class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};*/