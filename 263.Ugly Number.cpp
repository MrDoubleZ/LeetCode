class Solution {
public:
    bool isUgly(int num)
    {
        if(num<=0) return false;
        int arr[]={2,3,5};
        for(int i=0;i<=2;++i)
            while(num%arr[i]==0)
                num/=arr[i];
        return num==1; 
    }
};
