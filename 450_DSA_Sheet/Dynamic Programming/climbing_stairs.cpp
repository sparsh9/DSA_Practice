// Using Recursion, we see that it comes similar to fibonacci series

// Approach 1 (Using Memoization Top-Down)
class Solution {
public:
    void solve(int n,vector<int> &dp){
        //base case
        if(n<=2)
          return n;
        
        if(dp[n]!=-1) 
          return dp[n]; 
        
        dp[n]=solve(n-1)+solve(n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        if(n<=2)
         return n;
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++)
         dp[i]=-1;
        
        return solve(n,dp);
    }
};


// Further more optimization approach (Tabulation Bottom-Up)
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
         return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
         dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
    }
};


// Further we can do space optimization as in the fibonacci 
// we only require previous 2 values so we won't require an array
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};