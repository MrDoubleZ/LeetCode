class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if(grid.empty()) return 0;
        int m=grid.size(),n=grid[0].size();
        for(int i=1;i!=m;++i)
        {
            grid[i][0]+=grid[i-1][0];
        }
        for(int i=1;i!=n;++i)
        {
            grid[0][i]+=grid[0][i-1];
        }
        for(int j=1;j!=m;++j)
        {
            for(int i=1;i!=n;++i)
            {
                grid[j][i]+=min(grid[j][i-1],grid[j-1][i]);
            }
        }
        return grid[m-1][n-1];
    }
};