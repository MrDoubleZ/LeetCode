class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m=matrix.size(),n=matrix[0].size();
        int col0=matrix[0][0];
        for(int row=0;row!=m;++row)
        {
            for(int col=0;col!=n;++col)
            {
                if(matrix[row][col]==0)
                {
                    matrix[row][0]=0;  
                    if(col==0) col0=0;
                    else matrix[0][col]=0;
                }
            }
        }
        
        for(int col=1;col!=n;++col)
        {
            if(matrix[0][col]==0)
            {
                for(int row=1;row!=m;++row)
                {
                    matrix[row][col]=0;
                }
            }
        }
        for(int row=0;row!=m;++row)
        {
            if(matrix[row][0]==0)
            {
                for(int col=1;col!=n;++col)
                {
                    matrix[row][col]=0;
                }
            }
        }
        if(!col0)
        {
            for(int row=0;row!=m;++row)
            {
                matrix[row][0]=0;
            }
        }
        return;
    }
};