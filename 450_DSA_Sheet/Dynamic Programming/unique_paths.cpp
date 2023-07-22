// Approach 1 (Recursion)
// Time Complexity : O(2^(m+n))
// Space Complexity : O(m+n)
class Solution {
public:
    int helper(int i, int j, int m, int n) {
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        return helper(i+1, j, m, n) + helper(i, j+1, m, n);
    }

    int uniquePaths(int m, int n) {
        return helper(0, 0, m, n);
    }
};


// Approach 2 (Recursion + Memoization) (Top Down)
// Time Complexity : O(m*n)
// Space Complexity : O(m*n) + O(m+n) (Recursion Stack)
class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = helper(i-1, j, m, n, dp) + helper(i, j-1, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, m, n, dp);
    }
};



// Approach 3 (Tabulation) (Bottom Up)
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j==0) 
                    dp[i][j] = 1;
                
                else{
                    int up = (i-1 >= 0) ? dp[i-1][j] : 0;
                    int left = (j-1 >= 0) ? dp[i][j-1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};



// Approach 4 (Tabulation + Space Optimized) (Bottom Up)
// Time Complexity : O(m*n)
// Space Complexity : O(n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);

        for(int i=0;i<m;i++){
            vector<int> curr(n, 0);
            for(int j=0;j<n;j++){
                if(i == 0 && j==0) 
                    curr[j] = 1;
                
                else{
                    // checking if i-1 and j-1 are valid 
                    // if valid then add their values else add 0
                    int up = (i-1 >= 0) ? prev[j] : 0;
                    int left = (j-1 >= 0) ? curr[j-1] : 0;
                    // updating curr
                    curr[j] = up + left;
                }
            }
            // copying curr to prev
            prev = curr;
        }
        return prev[n-1];
    }
};