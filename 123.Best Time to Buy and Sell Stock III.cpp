class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int hold1=INT_MIN,hold2=INT_MIN;
        int release1=0,release2=0;
        for(size_t i=0;i!=prices.size();++i)
        {
            release2=max(release2,hold2+prices[i]);
            hold2=max(hold2,release1-prices[i]);
            release1=max(release1,hold1+prices[i]);
            hold1=max(hold1,-prices[i]);
        }
        return release2;
    }
};