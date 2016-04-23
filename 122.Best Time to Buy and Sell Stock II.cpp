class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        auto sz=prices.size();
        if(!sz) return 0;
        int sum=0;
        for(size_t i=1;i!=sz;++i)
        {
            int diff=prices[i]-prices[i-1];
            if(diff>0)
                sum+=diff;
        }
        return sum;
    }
};