class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int> > res;
        if (nums.size()<4) return res;
        sort(nums.begin(),nums.end());
        
        for (size_t a=0;a!=nums.size()-3;++a)
        {
            for (size_t b=a+1;b!=nums.size()-2;++b)
            {
                
                size_t c=b+1;
                size_t d=nums.size()-1;
                int needsum=target-nums[a]-nums[b];
                while(c<d)
                {
                    int sum=nums[c]+nums[d];
                    if (sum>needsum) --d;
                    else if(sum<needsum) ++c;
                    else
                    {
                        vector<int> quadruplet(4,0);
                        quadruplet[0]=nums[a];
                        quadruplet[1]=nums[b];
                        quadruplet[2]=nums[c];
                        quadruplet[3]=nums[d];
                        res.push_back(quadruplet);
                        while(c<d&&nums[c]==quadruplet[2])++c;
                        while(c<d&&nums[d]==quadruplet[3])--d;
                    }
                    
                    
                }
                while(b+1<nums.size()-2&&nums[b]==nums[b+1]) ++b;
               
            }
            while(a+1<nums.size()-3&&nums[a]==nums[a+1]) ++a;
        }
        return res;
        
    }
};