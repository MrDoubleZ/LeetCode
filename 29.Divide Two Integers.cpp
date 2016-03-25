class Solution {
public:
    int divide(int dividend, int divisor)
    {
        int indicator=1;
        if((divisor==0)||(divisor==-1&&dividend==INT_MIN)) return INT_MAX;
        else if(divisor==1) return dividend;
        else if((divisor<0&&dividend>0)||(divisor>0&&dividend<0)) indicator=0;
        long long part_dividend=dividend;
        long long part_divisor=divisor;
        if(divisor<0) part_divisor=-part_divisor;
        if(dividend<0) part_dividend=-part_dividend;
        long long diff=part_dividend-part_divisor;
        long long prev_diff;
        long long times=1;
        long long times_sum=0;
        while(true)
        {
            while(diff>0)
            {
                prev_diff=diff;
                //if(part_divisor>=1073741823)break;
                times=times<<1;
                part_divisor=part_divisor<<1;
                diff=part_dividend-part_divisor;
            }
            if(diff==0)
            {
                times_sum+=times;
                break;
            }
            else if(diff<0)
            {
                times=times>>1;
                part_dividend=prev_diff;
                part_divisor=abs(divisor);
                times_sum+=times;
                if(times==0) break;
                else
                {
                    times=1;
                    diff=part_dividend-part_divisor;
                }
            }
            
        }
        if(indicator) return times_sum;
        else return -times_sum;
    }
};

/*class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};*/