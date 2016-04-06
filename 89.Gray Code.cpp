class Solution {
public:
    vector<int> grayCode(int n)
    {
        if(n<0) return vector<int>();
        else if(n==0) return vector<int>(1,0);
        vector<int> res{0,1};
        int cnt=n;
        while(cnt-1)
        {
            int sz=res.size();
            for(int i=sz-1;i>=0;--i)
            {
                res.push_back(res[i]^(1<<(n-cnt+1)));
            }
            --cnt;
        }
        return res;
    }
};