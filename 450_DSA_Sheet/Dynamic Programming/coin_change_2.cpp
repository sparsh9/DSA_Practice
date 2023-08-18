// Approach (Using Memoization) (Bottom Up)
class Solution {
public:
    int helper(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp) {
        // Base Case
        if(amount == 0) return 1;

        if(ind==0){
            return (amount % coins[ind] == 0); // if true then 1 otherwise 0
        }

        // case of take and not take
        long not_take = helper(coins, ind-1, amount, dp);
        long take = 0;
        if(amount >= coins[ind]){
            take = helper(coins, ind, amount-coins[ind], dp);
        }
        return dp[ind][amount] = not_take + take;
        
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return helper(coins, n-1, amount, dp);
    }
};


// Approach (Using Tabulation) Top Down
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        // Base Case
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                // case of take and not take
                long not_take = dp[i-1][j];
                long take = 0;
                if(j >= coins[i-1]){
                    take = dp[i][j-coins[i-1]];
                }
                dp[i][j] = not_take + take;
            }
        }
        return dp[n][amount];
    }
};




// Approach (Tabulation Space Optimized)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);

        // Base Case
        dp[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                // case of take and not take
                long not_take = dp[j];
                long take = 0;
                if(j >= coins[i-1]){
                    take = dp[j-coins[i-1]];
                }
                dp[j] = not_take + take;
            }
        }
        return dp[amount];
    }
};