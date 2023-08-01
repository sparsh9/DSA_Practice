// A transaction is complete when a stock is bought and sold,
// if only either of them is done, it is not considered a transaction.
// So apart from the previous question, here we can do at most 2 transactions only.


// Approach 1 : Recursion

class Solution {
public:

    int helper(int ind, bool buy, vector<int>& prices, int n, int cap){
        if(ind == n || cap == 0) return 0;
        if(buy){
            int buyStock = helper(ind+1, false, prices, n, cap) - prices[ind];
            int notBuyStock = helper(ind+1, true, prices, n, cap);
            return max(buyStock, notBuyStock);
        }
        else{
            int sellStock = helper(ind+1, true, prices, n, cap-1) + prices[ind];
            int notSellStock = helper(ind+1, false, prices, n, cap);
            return max(sellStock, notSellStock);
        }
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return helper(0,true,prices,n,2);
    }
};





// Approach 2 : Memoization

class Solution {
public:
    int helper(int ind, int buy, vector<int>&prices, int n, int cap, vector<vector<vector<int>>>& dp) {
        if (ind == n || cap == 0) return 0;
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if (buy) return dp[ind][buy][cap] = max(-prices[ind] + helper(ind+1, 0, prices, n, cap, dp), 0 + helper(ind+1, 1, prices, n, cap, dp));
        else return dp[ind][buy][cap] = max(prices[ind] + helper(ind+1, 1, prices, n, cap-1, dp), 0 + helper(ind+1, 0, prices, n, cap, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 1, prices, n, 2, dp);
    }
};



// Approach 3 : Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        // base case
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<2;buy++){
                // we didn't took cap = 0 as its already returning 0 in memoization case as well
                for(int cap = 1;cap<=2;cap++){
                    if(buy == 1){
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};