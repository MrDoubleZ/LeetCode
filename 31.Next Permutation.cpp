class Solution {
public:
    void swap(vector<int>& nums,size_t i,size_t j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void reverse(vector<int>& nums,size_t i,size_t j)
    {
        while(i<j)
        {
            swap(nums,i,j);
            i+=1;
            j-=1;
        }
    }
    void nextPermutation(vector<int>& nums)
    {
        size_t i=nums.size()-1;
        
        while((i>=1)&&(nums[i-1]>=nums[i]))
        {
            i-=1;
        }
        if(i==0) reverse(nums,i,nums.size()-1);
        else
        {
            size_t smallest=nums.size()-1;
            while(smallest>=i)
            {
                if(nums[smallest]>nums[i-1])
                {
                    break;
                }
                --smallest;
            }
            swap(nums,i-1,smallest);
            reverse(nums,i,nums.size()-1);
        }
        
    }
};