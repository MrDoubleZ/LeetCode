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
            permutation.push_back(nums_left[0]);;
            nums_left.erase(nums_left.begin());
            back_tracking(nums_left,permutation,res);
            nums_left.push_back(permutation[permutation.size()-1]);
            permutation.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> permutation;
        back_tracking(nums,permutation,res);
        return res;
    }
};