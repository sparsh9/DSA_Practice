// Here similar to the unique paths 1, we have to find the number of unique paths from top left to bottom right
// just here we have some grids with obstacles, so we have to skip those grids with obstacles
// therefore we will mainly add one addtional case to previous cases
// that we check if the current grid has obstacle or not


// Approach 2 (Recursion + Memoization) (Top Down)
class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(obstacleGrid[i][j] == 1) return dp[i][j] = 0;

        return dp[i][j] = helper(i-1, j, m, n, dp, obstacleGrid) + helper(i, j-1, m, n, dp, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(m-1, n-1, m, n, dp, obstacleGrid);
    }
};



// Approach 3 (Tabulation) (Bottom Up)
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                    
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }else{
                    int up=0, left=0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<int>dp(m, 0);
        for(int i=0; i<n; i++){
            vector<int>temp(m, 0);
            for(int j=0; j<m; j++){
                if(obstacleGrid[i][j]==1){continue;}
                if(i==0 && j==0 && obstacleGrid[i][j]!=1){temp[j]=1;}
                if(i>0){temp[j]+=dp[j];}
                if(j>0){temp[j]+=temp[j-1];}
            }
            dp=temp;
        }
        return dp[m-1];
    }
};