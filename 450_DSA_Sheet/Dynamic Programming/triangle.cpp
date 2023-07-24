// Problem similar to Minimum Path Sum in 2D grid 
// Just here it is a triangle instead of a rectangle

// Approach 1 (Recursion) (Top Down)
// Time Complexity : O(2^n)
// Space Complexity : O(1)
class Solution {
public:
    int helper(vector<vector<int>> &triangle, int i, int j) {
        // base case
        if(i == triangle.size()) return 0;
        // out of bounds
        if(j < 0 || j >= triangle[i].size()) return INT_MAX;
        
        // return minimum of the two paths (down and down-diagonal)
        return triangle[i][j] + min(helper(triangle, i+1, j), helper(triangle, i+1, j+1));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(triangle, 0, 0);
    }
};


// Approach 2 (Recursion + Memoization) (Top Down)
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

class Solution {
public:
    int helper(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp) {
        // base case
        if(i == triangle.size()) return 0;
        // out of bounds
        if(j < 0 || j >= triangle[i].size()) return INT_MAX;
        // if already calculated
        if(dp[i][j] != -1) return dp[i][j];
        
        // return minimum of the two paths (down and down-diagonal)
        return dp[i][j] = triangle[i][j] + min(helper(triangle, i+1, j, dp), helper(triangle, i+1, j+1, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return helper(triangle, 0, 0, dp);
    }
};

// Whatever you write for recursion, the tabulation is always the opposite 
// such as in recursion we start from the top and go to the bottom and in tabulation we start from the bottom and go to the top
// Approach 3 (Tabulation) (Bottom Up)
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); // number of rows
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // fill the last row as we are starting from the bottom so all the columns in last row will be base cases
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int down_diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, down_diag);
            }
        }
        return dp[0][0];
    }
};


// Approach 4 (Tabulation) (Bottom Up) (Space Optimized)
// Time Complexity : O(m*n)
// Space Complexity : O(n)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); // number of rows
        
        vector<int> prev(n, 0);
        // fill the last row as we are starting from the bottom so all the columns in last row will be base cases
        for(int j=0; j<n; j++){
            prev[j] = triangle[n-1][j];
        }

        for(int i = n-2;i>=0;i--){
            vector<int> curr(i+1, 0);
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + prev[j];
                int down_diag = triangle[i][j] + prev[j+1];
                curr[j] = min(down, down_diag);
            }
            prev = curr;
        }
        return prev[0];
    }
};

