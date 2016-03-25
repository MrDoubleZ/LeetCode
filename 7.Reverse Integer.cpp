// ReverseInteger.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

/*class Solution {
public:
	double pow(double x, int n)
	{
		if (n == 1) return x;
		if (n == 0) return 1;
		int temp = x;
		for (int i = 0; i != n-1; ++i)
		{
			x = x*temp;
		}
		return x;
	}
	int reverse(int x)
	{
		if (x == -2147483648) return 0;
		bool flag = true;
		if (x < 0)
		{
			flag = false;
			x = -x;
		}
		vector<double> vec;
		double res = 0;
		while (x != 0)
		{
			//cout << x % 10 << endl;
			vec.push_back(x % 10);
			x = x / 10;
		}
		for (int i = 0; i != vec.size(); ++i)
		{
			//cout << pow(10, vec.size() - i - 1)<<"  "<<vec[i] * (double)pow(10, vec.size() - i - 1) << endl;
			res += vec[i] * pow(10, vec.size() - i - 1);
		}
		if (!flag)
		{
			res = -res;
			if (res < -2147483648) return 0;
			else return int(res);
		}
		else
		{
			if (res > 2147483647) return 0;
			else return int(res);
		}
	}
};*/
class Solution {
public:
	int reverse(int x) {
		long long res = 0;
		while (x) {
			cout << res << endl;
			res = res * 10 + x % 10;
			x /= 10;
		}
		return (res<INT_MIN || res>INT_MAX) ? 0 : res;
	}
};

int main()
{
	int i = -2147483648;
	Solution sol;
	cout << sol.reverse(i) << endl;
    return 0;
}

