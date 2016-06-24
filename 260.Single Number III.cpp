class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int x=0,a=0;
        vector<int> res;
        for(auto i:nums)
            x^=i;
        int bitmask=0x00000001;
        for(int i=0;i<31;++i)
        {
            if((x&bitmask)>>i)
                break;
            else
                bitmask=bitmask<<1;
        }
        for(auto i:nums)
            if((i&bitmask)==bitmask)
                a^=i;
        res.push_back(a^x);
        res.push_back(a);
        return res;
    }
};
