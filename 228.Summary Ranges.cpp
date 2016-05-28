class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> res;
        if(nums.empty()) return res;
        int offset=nums[0];
        int beg,end;
        for(int i=0;i<nums.size();++i)
        {
            beg=nums[i];
            while(i<nums.size()&&nums[i]==i+offset)++i;
            --i;
            end=nums[i];
            
            stringstream ss;
            string str;
            
            ss<<beg;
            if(end!=beg)
                ss<<"->"<<end;
            ss>>str;
            
            res.push_back(str);
            if(i+1<nums.size());
                offset=nums[i+1]-i-1;
        }
        return res;
    }
};