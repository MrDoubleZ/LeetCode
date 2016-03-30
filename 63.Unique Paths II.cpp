class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if(obstacleGrid.empty()||obstacleGrid[0][0]==1) return 0;
        for(int i=0;i!=obstacleGrid[0].size();++i)
        {
            if(obstacleGrid[0][i]==1)
            {
                for(int j=i;j!=obstacleGrid[0].size();++j)
                {
                    obstacleGrid[0][j]=0;
                }
                break;
            }
            else obstacleGrid[0][i]=1;
        }
        for(int i=1;i!=obstacleGrid.size();++i)
        {
            if(obstacleGrid[i][0]==1)
            {
                for(int j=i;j!=obstacleGrid.size();++j)
                {
                    obstacleGrid[j][0]=0;
                }
                break;
            }
            else obstacleGrid[i][0]=1;
        }
        for(int j=1;j!=obstacleGrid.size();++j)
        {
            for(int i=1;i!=obstacleGrid[0].size();++i)
            {
                if(obstacleGrid[j][i]==1) obstacleGrid[j][i]=0;
                else obstacleGrid[j][i]=obstacleGrid[j][i-1]+obstacleGrid[j-1][i];
            }
        }
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

/*others'solution*/
/*class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;//nice initial!
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};*/