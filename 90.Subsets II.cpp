class Solution {
public:
void dfs(vector<int>& nums,int start,vector<int> &subset,int len,vector<vector<int>> &res)
    {
        if(subset.size()==len)
        {
            res.push_back(subset);
            return;
        }
        for(int i=start;i!=nums.size();++i)
        {
            subset.push_back(nums[i]);
            dfs(nums,i+1,subset,len,res);
            subset.pop_back();
            while(i<nums.size()-1&&nums[i]==nums[i+1]) ++i;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> res(1,vector<int>());
        sort(nums.begin(),nums.end());
        vector<int> subset;
        for(int i=1;i<=nums.size();++i)
            dfs(nums,0,subset,i,res);
        return res;
    }
};