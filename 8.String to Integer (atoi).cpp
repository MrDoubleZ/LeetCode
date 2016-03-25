// atoi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
class Solution
{
public:
	int myAtoi(string str)
	{
		bool ctn = true;
		bool flag = true;
		int thres = 2;
		vector<int> vec;
		for (int i = 0; i != str.length(); ++i)
		{
			if (!ctn) break;
			if (thres == 0) break;
			char ca=str[i];
			if ((ca == 32) && (thres != 2)) break;
			if ((ca == 32) && (vec.size() == 0)) continue;
			else if ((ca == 32) && (vec.size() != 0))
			{
				ctn = false;
				continue;
			}
			if (ca == 43)
			{
				--thres;
				continue;
			}
			if ((ca == 45) && (vec.size() == 0))
			{
				flag = false;
				--thres;
				continue;
			}
			if ((ca < 48) || (ca>57)) ctn = false;
			else
			{
				vec.push_back(int(ca)-48);	
			}
		}
		long long res = 0;
		for (int i = 0; i != vec.size(); ++i)
		{
			//cout << vec[i] << endl;
			res = res * 10 + vec[i];
			//cout << res << endl;
			if ((res > INT_MAX) && (!flag)) return INT_MIN;
			if (res > INT_MAX) return INT_MAX;
		}
		if (!flag) res = -res;
		return res;
	}
};

int main()
{
	string s = "-9223372036854775809";
	Solution sol;
	cout << sol.myAtoi(s) << endl;
    return 0;
}

