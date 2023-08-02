// Here it is similar to buy and sell stocks with unlimited transactions,
// here just the twist is that, you cannot buy a stock on the next day of selling a stock.
// so we will simply modify the else consition of stock selling for this problem.


class Solution {
public:
    int helper (int ind, bool buy, vector<int> &prices, int n){
        // base case
        if(ind >= n) return 0;

        if(buy){
            int buyStock = helper(ind+1, false, prices, n) - prices[ind];
            int notBuyStock = helper(ind+1, true, prices, n);
            return max(buyStock, notBuyStock);
        }
        else{
            int sellStock = helper(ind+2, true, prices, n) + prices[ind];
            int notSellStock = helper(ind+1, false, prices, n);
            return max(sellStock, notSellStock);
        }
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return helper(0, true, prices, n);
    }
};




// Approach 2 : Using Memoization

class Solution {
public:
    int helper (int ind, bool buy, vector<int> &prices, int n, vector<vector<int>> &dp){
        // base case
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy){
            int buyStock = helper(ind+1, false, prices, n, dp) - prices[ind];
            int notBuyStock = helper(ind+1, true, prices, n, dp);
            return dp[ind][buy] = max(buyStock, notBuyStock);
        }
        else{
            int sellStock = helper(ind+2, true, prices, n, dp) + prices[ind];
            int notSellStock = helper(ind+1, false, prices, n, dp);
            return dp[ind][buy] = max(sellStock, notSellStock);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return helper(0, true, prices, n, dp);
    }
};



// Approach 3 : Using Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy){
                    int buyStock = dp[ind+1][false] - prices[ind];
                    int notBuyStock = dp[ind+1][true];
                    dp[ind][buy] = max(buyStock, notBuyStock);
                }
                else{
                    int sellStock = dp[ind+2][true] + prices[ind];
                    int notSellStock = dp[ind+1][false];
                    dp[ind][buy] = max(sellStock, notSellStock);
                }
            }
        }

        return dp[0][true];
    }
};



f