// Here apart from the normal buy sell stock problem, we have to pay a transaction fee for every transaction.
// So in this case we are considering to pay the fees after every sell,
// so after every sell, we additionally deduce the fees from the profit.


// Approach : Recursion + Memoization

class Solution {
public:
    int helper(int ind, bool buy, vector<int> &prices, int n, vector<vector<int>> &dp, int fee){
        // base case
        if(ind >= n) return 0;

        // memoization  
        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy){
            int buyStock = helper(ind+1, false, prices, n, dp, fee) - prices[ind];
            int notBuyStock = helper(ind+1, true, prices, n, dp, fee);
            return dp[ind][buy] = max(buyStock, notBuyStock);
        }
        else{
            int sellStock = helper(ind+1, true, prices, n, dp, fee) + prices[ind] - fee;
            int notSellStock = helper(ind+1, false, prices, n, dp, fee);
            return dp[ind][buy] = max(sellStock, notSellStock);
        }
    }


    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return helper(0, true, prices, n, dp, fee);
    }
};




// Approach : Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         //lest cobvert int memo
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        int n=prices.size();
     
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy)
                {
                    int not_buy= dp[index+1][1];
                    int buy= -prices[index]+ dp[index+1][0];
                    profit=max(buy,not_buy);
                }
                else
                {   
                    int sell=prices[index]-fee+dp[index+1][1];
                    int not_sell=dp[index+1][0];
                    profit=max(sell,not_sell);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
};