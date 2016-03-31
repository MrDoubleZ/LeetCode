class Solution {
public:
    //low efficiency
    int climbStairs(int n)
    {
        //recursive solution, low efficiency
        //if(n==0) return 0;
        //else if(n==1) return 1;
        //else if(n==2) return 2;
        //else return climbStairs(n-1)+climbStairs(n-2);
        
        //iterative solution
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int one_step=2;
        int two_step=1;
        int total=0;
        for(int i=3;i!=n+1;++i)
        {
            total=one_step+two_step;
            two_step=one_step;
            one_step=total;
        }
        return total;
    }
};