class Solution {
public:
	bool isValid(vector<string>& solution,int size,int row,int col)
	{
		for (int i = 0; i != row; ++i)
			if (solution[i][col] == 'Q')
				return false;
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
			if (solution[i][j] == 'Q')
				return false;
		for (int i = row - 1, j = col + 1; i >= 0 && j < size; --i, ++j)
			if (solution[i][j] == 'Q')
				return false;
		return true;
	}
	void back_tracking
		int& res,
		vector<string>& solution,
		int n,
		int row)
	{
		if (row == n)//get a correct solution
		{
			++res;
			return;
		}
		else //if (qnum<n&&pos<n*n)//complete the solution
		{
			for (int col = 0; col != n; ++col)
			{
				solution[row][col] = 'Q';
				if (isValid(solution,n, row, col))
				{
					back_tracking(res, solution, n, row+1);
				}
				solution[row][col] = '.';
			}

		}
		return;//invalid solution
	}
	int totalNQueens(int n)
	{
		int res=0;
		string str(n, '.');
		vector<string> solution(n, str);
		back_tracking(res, solution, n, 0);
		return res;
	}
};