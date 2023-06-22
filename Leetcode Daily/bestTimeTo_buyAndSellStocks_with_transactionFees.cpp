// Approach (Recursive Memoization DP)
// Here we have 3 conditions : buy,sell,rest
// as mentioned, fee is deduced after buy and sell, therefore we deduce that fee either while buying or while selling
// here intially we only have 1 option that is buy.

class Solution {
public:
    int buyOrSell(int i,bool buy,vector<int>& prices,vector<vector<int>>& dp,int fee)
    {
        if(i==prices.size())
            return 0;
        
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        
        int profit=0;
        
        // if it buy
        if(buy)
        {
            profit=max(
                -prices[i]+buyOrSell(i+1,0,prices,dp,fee), // it buyies
                0+buyOrSell(i+1,1,prices,dp,fee) // it rests
                );
        }
        // if it sells
        else
        {
            // we are considering to deduce fee when it sells
            profit=max(
                prices[i]+buyOrSell(i+1,1,prices,dp,fee)-fee, // it sells and fees is charged
                0+buyOrSell(i+1,0,prices,dp,fee) // it rests
                );
        }
        
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n=prices.size();
        // initiating a dp
        vector<vector<int>> dp(n,vector<int>(2,-1)); 
        
        // we pass true value to buy as intially we can only buy
        return buyOrSell(0,true,prices,dp,fee);
        
    }
};