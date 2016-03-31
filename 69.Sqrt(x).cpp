class Solution {
public:
	int mySqrt(int x)
	{
	    if(x<0) return INT_MIN;
		double n = 1;
		double prev_n = 0;
		while ((int)n != (int)prev_n)
		{
			prev_n = n;
			n = 0.5*(n + x / n);
		}
		return n;
	}
};