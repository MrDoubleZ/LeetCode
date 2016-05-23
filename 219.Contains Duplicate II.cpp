class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int,int> container;
        for(size_t i=0;i<nums.size();++i)
        {
            if(container.find(nums[i])!=container.end())
            {
                if(i-container[nums[i]]<=k)
                    return true;
            }
            container[nums[i]]=i;
        }
        return false;
    }
};