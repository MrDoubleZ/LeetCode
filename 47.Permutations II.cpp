class Solution {
public:
    void back_tracking(vector<int>& nums_left,
                       vector<int>& permutation,
                       vector<vector<int>>& res)
    {
        if(nums_left.size()==0)
        {
            res.push_back(permutation);
            return;
        }
        auto n=nums_left.size();
        for(int i=0;i!=n;++i)
        {
            permutation.push_back(nums_left[i]);;
            nums_left.erase(nums_left.begin()+i);
            back_tracking(nums_left,permutation,res);
            nums_left.insert(nums_left.begin()+i,permutation[permutation.size()-1]);
            permutation.pop_back();
            while(i!=n-1&&nums_left[i+1]==nums_left[i])++i;
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> permutation;
        sort(nums.begin(),nums.end());
        back_tracking(nums,permutation,res);
        return res;
    }
};