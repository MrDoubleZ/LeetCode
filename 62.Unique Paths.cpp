class Solution {
public:
    int uniquePaths(int m, int n)
    {   //low efficiency
        //if(m==1||n==1) return 1;
        //else return 2+uniquePaths(m-1,n)+uniquePaths(m,n-1);
        if(m>n) return uniquePaths(n,m);
        vector<int> curr(m,1);
        for(int j=1;j<n;++j)
        {
            for(int i=1;i!=m;++i)
            {
                curr[i]+=curr[i-1];
            }
        }
        return curr[m-1];
    }
};