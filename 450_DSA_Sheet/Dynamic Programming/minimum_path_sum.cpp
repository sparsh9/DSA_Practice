// Approach 1 (Using Recursion)
class Solution {
public:
    int helper(vector<vector<int>> &grid, int i, int j) {
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return INT_MAX;
        
        // return minimum of the two paths (left and up)
        return grid[i][j] + min(helper(grid, i-1, j), helper(grid, i, j-1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        return helper(grid, grid.size()-1, grid[0].size()-1);
    }
};


// Approach 2 (Recursion + Memoization) (Top Down)
class Solution {
public:
    int helper(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        // base case
        if(i == 0 && j == 0) return grid[i][j];
        // out of bounds
        if(i < 0 || j < 0) return INT_MAX;
        // if already calculated
        if(dp[i][j] != -1) return dp[i][j];
        
        // return minimum of the two paths (left and up)
        return dp[i][j] = grid[i][j] + min(helper(grid, i-1, j, dp), helper(grid, i, j-1, dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return helper(grid, m-1, n-1, dp);
    }
};


// Approach 3 (Tabulation) (Bottom Up)
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }else{
                    int up=INT_MAX, left=INT_MAX;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};


// Approach 4 (Tabulation) (Bottom Up) (Space Optimized)
// Time Complexity : O(m*n)
// Space Complexity : O(n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<int> dp(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[j] = grid[i][j];
                }else{
                    int up=INT_MAX, left=INT_MAX;
                    if(i>0) up = dp[j];
                    if(j>0) left = dp[j-1];
                    dp[j] = grid[i][j] + min(up, left);
                }
            }
        }
        
        return dp[n-1];
    }
};