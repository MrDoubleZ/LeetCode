class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> comb;
        dfs(res,comb,1,k,n,0);
        return res;
    }
private:
    void dfs(vector<vector<int>> &res,vector<int> &comb,int beg,int k,int n,int sum)
    {
        if(comb.size()==k&&sum==n)
        {
            res.push_back(comb);
            return;
        }
        for(int i=beg;i<=9;++i)
        {
            if(sum+i>n)
                break;
            if(comb.size()>=k)
                break;
            comb.push_back(i);
            dfs(res,comb,i+1,k,n,sum+i);
            comb.pop_back();
        }
    }
};