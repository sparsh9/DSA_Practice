// Approach: Recursion

class Solution {
public:
    int helper(int ind, bool buy, vector<int>& prices, int n){
        if(ind == n) return 0;
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
        return helper(0, 1,prices,n);
    }
};



// Memoization

class Solution {
public:
    int helper(int ind, int buy, vector<int>&prices, int n, vector<vector<int>>& dp) {
        if (ind == n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];
        if (buy) return dp[ind][buy] = max(-prices[ind] + helper(ind+1, 0, prices, n, dp), 0 + helper(ind+1, 1, prices, n, dp));
        else return dp[ind][buy] = max(prices[ind] + helper(ind+1, 1, prices, n, dp), 0 + helper(ind+1, 0, prices, n, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, n, dp);
    }
};





// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[0][1] = INT_MIN;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i-1][1] + prices[i-1], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] - prices[i-1], dp[i-1][1]);
        }
        return dp[n][0];
    }
};