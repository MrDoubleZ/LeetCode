class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        vector<pair<int,int>> dp(prices.size(),make_pair<int,int>(INT_MAX,INT_MIN));
        for(size_t i=0;i<prices.size();++i)
        {
            for(size_t j=0;j<dp.size();++j)
            {
                dp[j].second=max(dp[j].second,prices[i]-dp[j].first); 
                dp[j].first=min(dp[j].first,prices[i]);
            }
        }

        
    }
};


/*others solution, dp, java*/
public int maxProfit(int k, int[] prices) {
    int len = prices.length;
    if (k >= len / 2) return quickSolve(prices);

    int[][] t = new int[k + 1][len];
    for (int i = 1; i <= k; i++) {
        int tmpMax =  -prices[0];
        for (int j = 1; j < len; j++) {
            t[i][j] = Math.max(t[i][j - 1], prices[j] + tmpMax);//j-1时买进，j时卖出获得的profit
            tmpMax =  Math.max(tmpMax, t[i - 1][j - 1] - prices[j]);//t[i - 1][j - 1] - prices[j]是j-1时买进，j时卖出获得的profit，
                                                                    //整句的意思是得到一个更小的损失的点（当值为负时，max函数取到更靠近0的点，意思是卖出时的价位与买入时更接近）
                                                                    //当值为正时，就是盈利了
                                                                    //tmpMax means the maximum profit of just doing at most i-1 transactions，这是一次交易的利润而不是总利润
        }
    }
    return t[k][len - 1];
}


private int quickSolve(int[] prices) {
    int len = prices.length, profit = 0;
    for (int i = 1; i < len; i++)
        // as long as there is a price gap, we gain a profit.
        if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
    return profit;
}