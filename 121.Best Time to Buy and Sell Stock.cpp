class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        //dp
        auto sz=prices.size();
        if(!sz) return 0;
        vector<int> differenceArray(sz);
        vector<int> maxSubArray(sz);
        for(size_t i=1;i!=sz;++i)//differenceArray[0]==0
        {
            differenceArray[i]=prices[i]-prices[i-1];
        }
        for(size_t i=1;i!=sz;++i)//maxSubArray[0]==0
        {
            if(maxSubArray[i-1]<0)
                maxSubArray[i]=differenceArray[i];
            else
                maxSubArray[i]=differenceArray[i]+maxSubArray[i-1];
        }
        size_t maxIndice=0;
        for(size_t i=0;i!=sz;++i)
        {
            if(maxSubArray[i]>maxSubArray[maxIndice])
                maxIndice=i;
        }
        return maxSubArray[maxIndice];
    }
};

//[100,113,110,85,105,102,86,63,81,101,94,106,110,79,94,90,97]