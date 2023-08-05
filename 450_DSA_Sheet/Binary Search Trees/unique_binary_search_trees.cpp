// Approach 1 : (Identified the pattern as a Catalan Number)
// 1,1,2,5,....
// C(n+1) = Summation [C(k) * C(n-k)] with 0 <= k <= n 
// Therefore C(n)= Summation [C(k) * C(n-1-k)] with 0 <= k <= n-1

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);

        dp[0] = dp[1] = 1;

        for(int i=2;i<=n;i++){
            for(int k=0;k<i;k++){
                dp[i] += dp[k]*dp[i-1-k];
            }
        }
        return dp[n];
    }
};


// Approach : (Using recursion)

class Solution {
public:
    int helper(int start,int end){
        if(start>=end){
            return 1;
        }
        int ans = 0;
        for(int i=start;i<=end;i++){
            int left = helper(start,i-1);
            int right = helper(i+1,end);
            ans += left*right;
        }
        return ans;
    }

    int numTrees(int n) {
        return helper(1,n);
    }
};


// Approach : (Using Recursion + Memoization)

class Solution {
public:
    int helper(int start,int end,vector<vector<int>>& dp){
        if(start>=end){
            return 1;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int ans = 0;
        for(int i=start;i<=end;i++){
            int left = helper(start,i-1,dp);
            int right = helper(i+1,end,dp);
            ans += left*right;
        }
        return dp[start][end] = ans;
    }

    int numTrees(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(1,n,dp);
    }
};