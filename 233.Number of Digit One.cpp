class Solution {
public:
    int countDigitOne(int n)
    {
        int res=0;
        for(long long i=1;i<=n;i*=10)
        {
            int a=n/i;
            int b=n%i;
            switch(a%10)
            {
                case 0:
                {
                    res+=a/10*i;
                    break;
                }
                case 1:
                {
                    res+=a/10*i+(b+1);
                    break;
                }
                default:
                {
                    res+=(a/10+1)*i;
                    break;
                }
            }
        }
        return res;
    }
};