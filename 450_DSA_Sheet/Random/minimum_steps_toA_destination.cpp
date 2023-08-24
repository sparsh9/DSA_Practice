// Approach : Recursion

class Solution{
public:
    int helper(int source, int steps, int d){
        if(source == d) return steps;
        if(abs(source) > d) return INT_MAX;

        // towards left side in the number line
        int left = helper(source - steps - 1, steps + 1, d);
        // towards right side in the number line
        int right = helper(source + steps + 1, steps + 1, d);

        return min(left, right);
    }

    int minSteps(int D){
        return helper(0,0,D);
    }
};



// Approach : Recursion + Memoization

class Solution{
public:
    int helper(int source, int steps, int d, vector<vector<int>>& dp){
        if(source == d) return steps;
        if(abs(source) > d) return INT_MAX;
        if(dp[source][steps] != -1) return dp[source][steps];

        // towards left side in the number line
        int left = helper(source - steps - 1, steps + 1, d, dp);
        // towards right side in the number line
        int right = helper(source + steps + 1, steps + 1, d, dp);

        return dp[source][steps] = min(left, right);
    }

    int minSteps(int D){
        vector<vector<int>> dp(D+1, vector<int>(D+1, -1));
        return helper(0,0,D,dp);
    }
};



// Approach : Tabulation

class Solution{
public:
    int minSteps(int D){
        vector<vector<int>> dp(D+1, vector<int>(D+1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 0; i <= D; i++){
            for(int j = 0; j <= D; j++){
                if(dp[i][j] == INT_MAX) continue;
                // towards left side in the number line
                if(i + j + 1 <= D) dp[i+j+1][j+1] = min(dp[i+j+1][j+1], dp[i][j] + 1);
                // towards right side in the number line
                if(i - j - 1 >= 0) dp[i-j-1][j+1] = min(dp[i-j-1][j+1], dp[i][j] + 1);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i <= D; i++){
            ans = min(ans, dp[D][i]);
        }
        return ans;
    }
};