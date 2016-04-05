class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        //find mid
        int begin=0,end=nums.size()-1,mid=begin+(end-begin)/2;
        while(begin<end)
        {
            if(nums[mid]==target||nums[begin]==target||nums[end]==target) return true;
            
            if(nums[mid]>nums[end])
            {
                if(nums[mid]>target&&target>nums[begin])
                {
                    end=mid;
                }
                else
                {
                    begin=mid+1;
                }
            }
            else if(nums[mid]<nums[end])
            {
                if(nums[mid]<target&&target<nums[end])
                {
                    begin=mid+1;
                }
                else
                {
                    end=mid;
                }
            }
            else --end;
            mid=begin+(end-begin)/2;
        }
        return  nums[begin] == target ? true : false;
    }
};