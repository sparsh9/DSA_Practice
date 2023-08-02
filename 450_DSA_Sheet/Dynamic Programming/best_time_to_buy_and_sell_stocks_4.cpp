// Approach 1 : Using Recursion

class Solution {
public:
    int helper(int ind, bool buy, vector<int> &prices, int n, int k){
        // base case
        if(ind == n || k == 0) return 0;

        if(buy){
            int buyStock = helper(ind+1, false, prices, n, k) - prices[ind];
            int notBuyStock = helper(ind+1, true, prices, n, k);
            return max(buyStock, notBuyStock);
        }
        else{
            int sellStock = helper(ind+1, true, prices, n, k-1) + prices[ind];
            int notSellStock = helper(ind+1, false, prices, n, k);
            return max(sellStock, notSellStock);
        }
        
    }


    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        return helper(0, true, prices, n, k);
    }
};




// Approach 2 : Using Memoization

class Solution {
public:
    int helper(int ind, int buy, vector<int> &prices, int n, int k, vector<vector<vector<int>>> &dp){
        // base case
        if(ind == n || k == 0) return 0;
        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];

        if(buy){
            int buyStock = helper(ind+1, false, prices, n, k, dp) - prices[ind];
            int notBuyStock = helper(ind+1, true, prices, n, k, dp);
            return dp[ind][buy][k] = max(buyStock, notBuyStock);
        }
        else{
            int sellStock = helper(ind+1, true, prices, n, k-1, dp) + prices[ind];
            int notSellStock = helper(ind+1, false, prices, n, k, dp);
            return dp[ind][buy][k] = max(sellStock, notSellStock);
        }
        
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return helper(0, true, prices, n, k, dp);
    }
};




// Approach 3 : Using Tabulation

class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for (int ind=n-1; ind>=0; ind--) {
            for (int buy=0; buy<=1; buy++) {
                for (int cap=1; cap<=k; cap++) {
                    if (buy) dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    else dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][k];
    }
};
