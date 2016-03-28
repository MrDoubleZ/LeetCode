class Solution {
public:
    void recursive(vector<vector<int>>& matrix,
                   vector<int>& res,
                   int row_size,
                   int col_size,
                   int row,
                   int col)
    {
        int i,j,k;
        for(i=col,j=row,k=0;k<col_size;++i,++k)
        {
            res.push_back(matrix[j][i]);
        }
        --i;
        for(j=row+1,k=0;k<row_size-1;++j,++k)
        {
            res.push_back(matrix[j][i]);
        }
        --j;
        if(row_size!=1&&col_size!=1)
        {
            for(i=i-1,k=0;k<col_size-1;--i,++k)
            {
                res.push_back(matrix[j][i]);
            }
            ++i;
            for(j=j-1,k=0;k<row_size-2;--j,++k)
            {
                res.push_back(matrix[j][i]);
            }
            ++j;
        }
        if (row_size==1||col_size==1) return;
        else if(row_size==2||col_size==2) return;
        return recursive(matrix,res,row_size-2,col_size-2,j,i+1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;
        recursive(matrix,res,matrix.size(),matrix[0].size(),0,0);
        return res;
    }
};
/*others' solution*/
/*class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral(m * n);
        int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
        while (true) {
            // up
            for (int col = l; col <= r; col++) spiral[k++] = matrix[u][col];
            if (++u > d) break;
            // right
            for (int row = u; row <= d; row++) spiral[k++] = matrix[row][r];
            if (--r < l) break;
            // down
            for (int col = r; col >= l; col--) spiral[k++] = matrix[d][col];
            if (--d < u) break;
            // left
            for (int row = d; row >= u; row--) spiral[k++] = matrix[row][l];
            if (++l > r) break;
        }
        return spiral;
    }
};*/
