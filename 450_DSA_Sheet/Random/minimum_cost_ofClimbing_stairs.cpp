// Approach : Recursion

class Solution {
public:
    int Recursive(int n, vector<int> &cost){
        //BASE CASE
        if (n <= 1)
            return cost[n];

        //0 - n-1 step tak aane ka cost + n-1 se n tak jaane ka cost
        //One Step Case
        int OneStep = Recursive(n - 1, cost) + cost[n];
        
        //0 - n-2 step tak aane ka cost + n-1 se n tak jaane ka cost
        //Two Step Case
        int TwoStep = INT_MAX;
        if (n > 1)
            TwoStep = Recursive(n - 2, cost) + cost[n];
        
        //Min of both 
        return min(OneStep, TwoStep);
    }
    int minCostClimbingStairs(vector<int> &cost){
        int n = cost.size();
        
        //Oth ya 1st jis step se start karne pe min cost mile.
        return min(Recursive(n - 1, cost), Recursive(n - 2, cost));
    }
};



// Approach : Recursion + Memoization

class Solution {
public:
    int helper(int n, vector<int> &cost, vector<int> &dp){
        //BASE CASE
        if (n <= 1)
            return cost[n];
        
        // if already calculated
        if (dp[n] != -1)
            return dp[n];

        // for 1 step case from 0 to n-1
        int left = helper(n - 1, cost, dp) + cost[n];

        // for 2 step case from 0 to n-2
        int right = INT_MAX;
        if (n > 1)
            right = helper(n - 2, cost, dp) + cost[n];
        
        return dp[n] = min(left, right);
    }
    int minCostClimbingStairs(vector<int> &cost){
        int n = cost.size();
        vector<int> dp(n, -1);

        // either start from 0th step or 1st step
        return min(helper(n - 1, cost, dp), helper(n - 2, cost, dp));
    }
};



// Approach : Tabulation

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost){
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        // 0th and 1st step pe pahuchne ka cost 0
        dp[0] = dp[1] = 0;

        // 2nd step se start karenge
        for (int i = 2; i <= n; i++){
            // 1 step se aane ka cost + 1 step aage jaane ka cost
            int OneStep = dp[i - 1] + cost[i - 1];

            // 2 step se aane ka cost + 2 step aage jaane ka cost
            int TwoStep = INT_MAX;
            if (i > 1)
                TwoStep = dp[i - 2] + cost[i - 2];
            
            // Min of both
            dp[i] = min(OneStep, TwoStep);
        }
        return dp[n];
    }
};