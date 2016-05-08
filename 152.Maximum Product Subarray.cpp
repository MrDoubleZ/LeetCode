//思路有问题，希望通过找到“以每个元素结尾的子串的最大积”，再遍历这个构造的数组，找到最大积，但是实际上并不好找，这与找最大和不同，因为很难确定何时抛弃前面的值，选取新的起点
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        vector<int> dp(nums.size()+1);
        dp[0]=1;
        stack<int> non_positive;
        for(int i=nums.size()-1;i>=0;--i)
        {
            if(nums[i]<=0)
                non_positive.push(nums[i]);
        }
        for(size_t i=1;i<=nums.size();++i)
        {
            if(nums[i-1]==0)
            {
                dp[i]=0;
                non_positive.pop();
                continue;
            }
            else if(dp[i-1]==0)
            {
                dp[i]=nums[i-1];
            }
            else if((nums[i-1]>0&&dp[i-1]>0)||(nums[i-1]<0&&dp[i-1]<0))
            {
                dp[i]=nums[i-1]*dp[i-1];
            }
            else if(nums[i-1]<0&&dp[i-1]>0)
            {
                non_positive.pop();
                if(!non_positive.empty()&&non_positive.top()<0)//next non_positive is not 0
                    dp[i]=nums[i-1]*dp[i-1];
                else
                    dp[i]=nums[i-1];
            }
            else//nums[i-1]>0&&dp[i-1]<0
            {
                if(!non_positive.empty()&&non_positive.top()<0)//next non_positive is not 0
                    dp[i]=nums[i-1]*dp[i-1];
                else
                    dp[i]=nums[i-1];
            }
        }
        int res=INT_MIN;
        for(size_t i=1;i<dp.size();++i)
        {
            res=max(res,dp[i]);
        }
        return res;
    }
};

/*others solution*/
int maxProduct(int A[], int n) {
    // store the result that is the max we have found so far
    int r = A[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}


class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
       int res=nums[0];
       int imax = res, imin = res;
       for(size_t i=1;i<nums.size();++i)
       {
            if(nums[i]<0)
               swap(imax,imin);
            imax=max(nums[i],imax*nums[i]);
            imin=min(nums[i],imin*nums[i]);
            res=max(res,imax);
       }
       return res;
    }
};