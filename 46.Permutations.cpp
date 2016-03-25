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

/*others' solution*/
/*class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;

        permuteRecursive(num, 0, result);
        return result;
    }

    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
};*/