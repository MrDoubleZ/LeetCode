class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x>=0&&x<10) return true;
        /*while (0!=x/10)
        {
            int low=x%10;
            int temp=x;
            int cnt=0;
            while (0!=temp/10) 
            {
               temp=temp/10;
               ++cnt;
            }
            int high=temp;
            printf("%d\n",temp);
            if (high!=low) return false;
            x=(x-high*pow(10,cnt))/10;
        }
        return true;*/
        int temp=x;
        int cnt=1;
        while (0!=temp/10) 
        {
            temp=temp/10;
            ++cnt;
        }
        for (int i=0;i!=cnt/2;++i)
        {
            int low=int(x/(pow(10,i)))%10;
            int high=int(x/(pow(10,cnt-i-1)))%10;
            //printf("%d %d\n",low,high);
            if (low!=high) return false;
        }
        return true;
    }
};