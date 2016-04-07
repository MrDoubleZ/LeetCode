class Solution {
public:
    void dfs(vector<int>& nums,unsigned int bitmap,vector<int> &subset,int len,vector<vector<int>> &res)
    {
        if(subset.size()==len)
        {
            res.push_back(subset);
            return;
        }
        for(int i=0;i!=nums.size();++i)
        {
            if(!((1<<(i)&bitmap)>>i)) continue;
            bitmap&=(~(1<<i))&bitmap;
            subset.push_back(nums[i]);
            dfs(nums,bitmap,subset,len,res);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res(1,vector<int>());
        sort(nums.begin(),nums.end());
        unsigned int bitmap=(1<<nums.size())-1;
        vector<int> subset;
        for(int i=1;i<=nums.size();++i)
            dfs(nums,bitmap,subset,i,res);
        return res;
    }
};
/*others' solution*/
/*class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};*/