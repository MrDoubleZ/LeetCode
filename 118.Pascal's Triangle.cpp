class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        if(!numRows) return vector<vector<int>>();
        vector<vector<int>> res{1,vector<int>(1,1)};
        for(int i=1;i<numRows;++i)
        {
            vector<int> level(i+1);
            int indice=0;
            level[indice++]=1;
            for(;indice<=i-1;++indice)
            {
                level[indice]=res[i-1][indice-1]+res[i-1][indice];
            }
            level[indice]=1;
            res.push_back(level);
        }
        return res;
    }
};

/*less time cost*/
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for(int i=0;i<numRows;++i)
        {
            //res[i].resize(i+1);
            res.push_back(vector<int>(i+1));
            res[i][0]=1;
            for(int j=1;j<=i-1;++j)
            {
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
            res[i][i]=1;
        }
        return res;
    }
};