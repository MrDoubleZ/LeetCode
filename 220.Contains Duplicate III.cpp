class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int64_t k, int64_t t)
    {
        if (k < 1 || t < 0) return false;
        unordered_map<int64_t,int64_t> map;
        for(int i=0;i<nums.size();++i)
        {
            int64_t value=static_cast<int64_t>(nums[i])-INT_MIN;
            int64_t bucket=value/(t+1);
            if(map.find(bucket)!=map.end()
                ||(map.find(bucket+1)!=map.end()&&map[bucket+1]-value<=t)
                ||(map.find(bucket-1)!=map.end()&&value-map[bucket-1]<=t))
                return true;
            if(map.size()>=k)
                map.erase((static_cast<int64_t>(nums[i-k])-INT_MIN)/(t+1));
            map[bucket]=value;
        }
        return false;
    }
};