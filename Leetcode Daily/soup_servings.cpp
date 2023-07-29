// Approach Using DP Memoization

class Solution {
public:
    double helper(int a,int b,vector<vector<double>>&dp){
        // Base Case
        if(a<=0 && b<=0)return 0.5;
        // If a is less than 0 then we can't serve soup A
        if(a<=0) return 1.0;
        // If b is less than 0 then we can't serve soup B
        if(b<=0) return 0.0;

        // If we have already calculated the value of dp[a][b] then return it
        if(dp[a][b]>-1)return dp[a][b];

        // Else we will calculate the value of dp[a][b] using the formula given in the question
        vector<pair<int,int>>x = {{100,0}, {75,25} , {50,50}, {25,75}};

        double ans = 0.0;
        for(int i=0;i<4;i++){
            ans += 0.25 * helper(a-x[i].first,b-x[i].second,dp);
        }
        
        return dp[a][b] = ans;
    }

    double soupServings(int n) {

      if(n>5000)return 1.0; // Observation (try to run test cases greater than 5000)
      
      vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
      
      return helper(n,n,dp);  
    }
};