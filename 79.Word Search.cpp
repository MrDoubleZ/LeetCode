class Solution {
public:
    void back_tracking(vector<vector<char>>& board,string word,string curr,int row,int col,bool &find)
    {
        if(word==curr)
        {
            find=true;
            return;
        }
        if(find) return;
        char next_char=*(word.begin()+curr.size());
        if(row-1>=0&&board[row-1][col]==next_char)//top
        {
            board[row-1][col]='\0';
            back_tracking(board,word,curr+next_char,row-1,col,find);
            board[row-1][col]=next_char;
        }
        if(col-1>=0&&board[row][col-1]==next_char)//left
        {
            board[row][col-1]='\0';
            back_tracking(board,word,curr+next_char,row,col-1,find);
            board[row][col-1]=next_char;
        }
        if(row+1<board.size()&&board[row+1][col]==next_char)//bottom
        {
            board[row+1][col]='\0';
            back_tracking(board,word,curr+next_char,row+1,col,find);
            board[row+1][col]=next_char;
        }
        if(col+1<board[0].size()&&board[row][col+1]==next_char)//right
        {
            board[row][col+1]='\0';
            back_tracking(board,word,curr+next_char,row,col+1,find);
            board[row][col+1]=next_char;
        }
        return;
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        if(board.empty()||board[0].empty()) return false;
        bool find=false;
        for(int i=0;i!=board.size();++i)
        {
            for(int j=0;j!=board[0].size();++j)
            {
                if(board[i][j]==word[0])
                {
                    char head=word[0];
                    board[i][j]='\0';
                    back_tracking(board,word,string(&head),i,j,find);
                    board[i][j]=head;
                }
            }
        }
        return find;
    }
};

/*another solution*/
//using pointer instead of string object 
//in bt func's parameter list to cut back function call cost 
/*class Solution {
private:
    int m;
    int n;
public:
    bool back_tracking(vector<vector<char>>& board,const char *word,int row,int col)
    {
        if(row<0||col<0||row>=m||col>=n||board[row][col]=='\0'||(*word)!=board[row][col]) return false;
        if(*(word+1)=='\0') return true;
        char temp=board[row][col];
        board[row][col]='\0';
        if(back_tracking(board,word+1,row-1,col)||
            back_tracking(board,word+1,row,col-1)||
            back_tracking(board,word+1,row+1,col)||
            back_tracking(board,word+1,row,col+1))
            return true;
        board[row][col]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        m=board.size();
        n=board[0].size();
        for(int i=0;i!=m;++i)
        {
            for(int j=0;j!=n;++j)
            {
                if(board[i][j]==word[0])
                    if(back_tracking(board,word.c_str(),i,j)) return true;
                    
            }
        }
        return false;
    }
};*/