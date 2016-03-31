class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if(matrix.empty()||matrix[0].empty()) return false;
        int m=matrix.size(),n=matrix[0].size();
        int begin=0,end=m*n;
        int mid=begin+(end-begin)/2;
        while(begin<end)
        {
            int row=mid/n;
            int col=mid%n;
            if(target>matrix[row][col])
                begin=mid+1;
            else if(target<matrix[row][col])
                end=mid;
            else return true;
            mid=begin+(end-begin)/2;
        }
        return false;
    }
};