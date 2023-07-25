// Here as similar to 0/1 knapsack problem, we are solving, just there are few points to clear
// 1) if we take a coin, then we can take it again, so we are not reducing the index instead we are reducing the target
// 2) if we don't take a coin, then we are reducing the index
// 3) if a coin is greater than the target, then we can't take it, so we are not reducing the index
// 4) if we reach the base case where the coin is of denomination of multiple of the then target, then only we can make it otherwise not


// Approach (Using Memoization)

class Solution {
public:
    int f(int ind, int sum, vector<int> &coins,vector<vector<int>>&dp){
        if(ind==0){
            if(sum%coins[0]==0)   
                return sum/coins[0];

            return 1e9;
        }
        if(dp[ind][sum]!=-1)    return dp[ind][sum];
        int notTake=0+f(ind-1,sum,coins,dp);
        int take=INT_MAX;
        if(coins[ind]<=sum){
            take=1+f(ind,sum-coins[ind],coins,dp);
        }
        return dp[ind][sum]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);
        if(ans>=1e9)   {
            return -1;
        }
        else{
            return ans;
        }
    }
};


// Approach (Using Tabulation)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                int notTake=0;
                if(i==0){
                    if(j%coins[0]==0){
                        notTake=j/coins[0];
                    }
                    else{
                        notTake=1e9;
                    }
                }
                else{
                    notTake=dp[i-1][j];
                }
                int take=1e9;
                if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(take,notTake);
            }
        }
        if(dp[n-1][amount]>=1e9){
            return -1;
        }
        else{
            return dp[n-1][amount];
        }
    }
};