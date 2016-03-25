// ZigZag.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
/*class Solution {
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1) return s;
		vector<string> row_res(numRows);
		for (int i = 0; i != s.length(); ++i)
		{
			int row = i % (2 * numRows - 2);
			if (row+1 > numRows)
				row = numRows - (row + 1 - numRows) - 1;
			row_res[row] += s[i];
		}
		string res;
		for (int i = 0; i != numRows; ++i)
		{
			res += row_res[i];
		}
		return res;

	}
};*/

class Solution {
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1) return s;
		string* row_res=new string[numRows];
		for (int i = 0; i != s.length(); ++i)
		{
			int row = i % (2 * numRows - 2);
			if (row + 1 > numRows)
				row = numRows - (row + 1 - numRows) - 1;
			*(row_res+row) += s[i];
		}
		string res;
		for (int i = 0; i != numRows; ++i)
		{
			res += *(row_res+i);
		}
		return res;

	}
};

int main()
{
	string s("P");
	Solution sol;
	string res=sol.convert(s, 1);
	cout << res << endl;
    return 0;
}

