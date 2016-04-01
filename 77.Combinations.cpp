class Solution {
public:
    void back_tracking(vector<int> &nums_set,
                       vector<vector<int>> &res,
                       int n,int k,int pos,int length)
    {
        if(length==k)
        {
            res.push_back(nums_set);
            return;
        }
        if(n-pos+length<k) return;//if statement is ture, it means that we cannot get a combination long enough.
        for(int i=pos;i<n;++i)
        {
            nums_set.push_back(i+1);
            back_tracking(nums_set,res,n,k,i+1,length+1);
            nums_set.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> nums_set;
        vector<vector<int>> res;
        back_tracking(nums_set,res,n,k,0,0);
        return res;
    }
};

/*others' solution*/
/*class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) --i;
            else if (i == k - 1) result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;
    }
};*/