class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size()<=2) return nums.size();
        int i=1,j=1,cnt=1,n=nums.size();
        while(j<n)
        {
            if(nums[j-1]==nums[j])
            {
                if(cnt<2)
                {
                    nums[i++]=nums[j];
                    ++cnt;
                }
            }
            else 
            {
                cnt=1;
                nums[i++]=nums[j];
            }
            ++j;
        }
        return i;
        
    }
};

/*another solution*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
         int i=2,cnt=0,n=nums.size();
         while(i<n)
         {
            if(nums[i-2-cnt]!=nums[i])
                nums[i-cnt]=nums[i];
            else
                ++cnt;
            ++i;
         }
         return n-cnt;
    }
};