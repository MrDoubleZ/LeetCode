class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int row_used[9][9]={0};
        int col_used[9][9]={0};
        int sub_used[9][9]={0};
        for(decltype(board.size()) i=0;i!=board.size();++i)
        {
            for(decltype(board.size()) j=0;j!=board.size();++j)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'0'-1;
                    int k=(i/3)*3+j/3;
                    if(row_used[i][num]||col_used[j][num]||sub_used[k][num])
                    {
                        return false;
                    }
                    else
                    {
                        row_used[i][num]=1;
                        col_used[j][num]=1;
                        sub_used[k][num]=1;
                    }
                }
            }
        }
        return true;
    }
};