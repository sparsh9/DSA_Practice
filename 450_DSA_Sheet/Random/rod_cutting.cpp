// Approach : Recursion + Memoization

class Solution{
  public:
      int solve(int price[], int n, int id,vector<vector<int>>&dp){
        // base cases
        if(n==0)return 0;
        if(id<0||n<0)return INT_MIN;

        if(dp[n][id]!=-1)return dp[n][id];

        int not_cut = solve(price,n,id-1,dp);
        
        int cut = INT_MIN;
        int rod_size = id+1;
        if(rod_size <= n){
            cut = price[id] + solve(price,n-rod_size,id,dp);
        }
        
        return dp[n][id]=max(cut,not_cut);
    }
  
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(price,n,n-1,dp);
    }
};
