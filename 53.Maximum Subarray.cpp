class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        vector<int> s(nums.size());
        int sum=INT_MIN;
        for(int i=0;i!=nums.size();++i)
        {
            if(sum>0)
            {
                sum+=nums[i];
            }
            else
            {
                sum=nums[i];
            }
            s[i]=sum;
        }
        int max_sum=INT_MIN;
        for(int i=0;i!=s.size();++i)
        {
            if(s[i]>max_sum)max_sum=s[i];
        }
        return max_sum;
    }
};
/*others' solution*/
/*class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans=A[0],i,j,sum=0;
        for(i=0;i<n;i++){
            sum+=A[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;
    }
};*/