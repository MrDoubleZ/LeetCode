class Solution {
public:
	void recursive(vector<vector<int>>& res, int size, int num, int row, int col)
	{
		if (size == 1)
		{
			res[row][col] = num;
			return;
		}
		int i, j, k;
		for (i = col, j=row,k = 0; k != size; ++i, ++k)
		{
			res[j][i] = num;
			++num;
		}
		--i;
		for (j = row + 1, k = 0; k != size - 1; ++j, ++k)
		{
			res[j][i] = num;
			++num;
		}
		--j;
		for (i = i - 1, k = 0; k != size - 1; --i, ++k)
		{
			res[j][i] = num;
			++num;
		}
		++i;
		for (j = j - 1, k = 0; k != size - 2; --j, ++k)
		{
			res[j][i] = num;
			++num;
		}
		++j;
		if(size==2) return;
		else if(size==3)
		{
		    res[j][i+1]=num;
		    return;
		}
		else return recursive(res, size - 2, num, j, i + 1);
	}
	vector<vector<int>> generateMatrix(int n)
	{
		
		if (n <= 0) return vector<vector<int>>();
		vector<vector<int>> res(n, vector<int>(n));
		recursive(res, n, 1, 0, 0);
		return res;
	}
};