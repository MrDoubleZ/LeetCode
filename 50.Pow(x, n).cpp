class Solution {
public:
	double recursive_pow(double x, int n, double curr_x, int curr_n)
	{
		if (curr_n == n) return curr_x;
		else if (curr_n<=n / 2)
		{
			curr_x *= curr_x;
			return recursive_pow(x, n, curr_x, 2 * curr_n);
		}
		else if (curr_n > n / 2)
		{
			curr_x *= recursive_pow(x, n-curr_n, x, 1);
			return curr_x;
		}
	}
	double myPow(double x, int n)
	{
	    if(n==0) return 1.0;
	    else if (n>0) return recursive_pow(x, n, x, 1);
		else return 1/recursive_pow(x, -n, x, 1);
	}
};