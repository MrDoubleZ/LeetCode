class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
       vector<vector<int>> res;
       sort(nums.begin(), nums.end());
       for (size_t i=0;i!=nums.size();++i)
       {
           int target=-nums[i];
           if(target<0) break;
           int left=i+1;
           int right=nums.size()-1;
           
           while(left<right)
           {
               int sum=nums[left]+nums[right];
               if (target>sum) ++left;
               else if(target<sum) --right;
               else
               {
                   vector<int> temp(3,0);
                   temp[0]=nums[i];
                   temp[1]=nums[left];
                   temp[2]=nums[right];
                   res.push_back(temp);
                   while(left<right&&nums[left]==temp[1]) ++left;
                   while(left<right&&nums[right]==temp[2]) --right;
                   
               }
           }
           while(i+1<nums.size()&&nums[i+1]==nums[i]) ++i;
       }
       return res;
    }
};