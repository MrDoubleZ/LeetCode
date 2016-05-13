class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int n=nums.size();
        if(!n||k<0) return;
        k%=n;
        size_t curr=0;
        vector<int> left(nums.begin(),nums.begin()+n-k);
        for(;curr<k;++curr)
            nums[curr]=nums[curr+n-k];
        for(;curr<n;++curr)
            nums[curr]=left[curr-k];
        return;
    }
};
