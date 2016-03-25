class Solution {
public:
    void back_tracking(vector<int>& candidates,
                       vector<int>& each_res,
                       vector<vector<int>>& res,
                       int target,
                       int pos,
                       int sum)
    {
        if (sum==target)
        {
            res.push_back(each_res);
            return;
        }
        else if (sum>target) return;
        for(int i=pos;i!=candidates.size();++i)
        {
            while(i!=candidates.size()-1&&candidates[i+1]==candidates[i])++i;
            each_res.push_back(candidates[i]);
            back_tracking(candidates,each_res,res,target,i,sum+candidates[i]);
            each_res.pop_back();
        }
        return;  
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> each_res;
        back_tracking(candidates,each_res,res,target,0,0);
        return res;
    }
};