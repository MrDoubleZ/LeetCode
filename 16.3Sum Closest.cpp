class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
       sort(nums.begin(), nums.end());
       int diff=INT_MAX;
       int diffsig=1;
       for (size_t i=0;i!=nums.size();++i)
       {
           int tar=target-nums[i];
           //if(tar<0) break;
           int left=i+1;
           int right=nums.size()-1;
           while(left<right)
           {
               int sum=nums[left]+nums[right];
               if (abs(tar-sum)<diff)
               {
                   diff=abs(tar-sum);
                   diffsig=(tar>sum)?1:-1;
               }
               
               if (tar>sum) 
               {
                   ++left;  
               }
               else if(tar<sum)
               {
                   --right;
               }
               else return target;
           }
       }
       return target-diff*diffsig;
    }
};