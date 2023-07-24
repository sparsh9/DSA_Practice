// Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/

// Approach 1 (Recursion) (Top Down)
// Time Complexity : O(2^n)
// Space Complexity : O(1)
class Solution {
public:

    int mod=1e9+7;
    int helper(vector<vector<int>>&mat, int i,int j,int n,int m){
        // base case
        if(i==0) return mat[i][j];

        // out of bounds
        if(j<0 || j>m-1) return mod;

        // return minimum of the three paths (up, up-left and up-right)
        int up=mat[i][j]+helper(mat,i-1,j,n,m);
        int up_left=mat[i][j]+helper(mat,i-1,j-1,n,m);
        int up_right=mat[i][j]+helper(mat,i-1,j+1,n,m);

        return min(up,min(up_left,up_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MAX;
        for(int i=0;i<m;++i){
            ans=min(ans,helper(matrix,n-1,i,n,m));
        }
        return ans;
    }
};


// Approach 2 (Recursion + Memoization) (Top Down)
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

class Solution {
public:

    int mod=1e9+7;
    int helper(vector<vector<int>>&mat, int i,int j,int n,int m,vector<vector<int>>&dp){
        // base case
        if(i==0) return mat[i][j];
        
        // out of bounds
        if(j<0 || j>m-1) return mod;
        
        // if already calculated
        if(dp[i][j]!=-1) return dp[i][j];

        // return minimum of the three paths (up, up-left and up-right)
        int up=mat[i][j]+helper(mat,i-1,j,n,m,dp);
        int down=mat[i][j]+helper(mat,i-1,j-1,n,m,dp);
        int right=mat[i][j]+helper(mat,i-1,j+1,n,m,dp);

        return dp[i][j]=min(up,min(down,right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,helper(matrix,n-1,j,n,m,dp));
        }
        return ans;
    }
};



// Approach 3 (Tabulation) (Bottom Up)
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,0));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=INT_MAX,up_left=INT_MAX,up_right=INT_MAX;
                if(j>0) up_left=dp[i-1][j-1];
                if(j<m-1) up_right=dp[i-1][j+1];
                up=dp[i-1][j];
                dp[i][j]=matrix[i][j]+min(up,min(up_left,up_right));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};



// Approach 4 (Tabulation) (Bottom Up) (Space Optimized)
// Time Complexity : O(m*n)
// Space Complexity : O(1)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=INT_MAX,up_left=INT_MAX,up_right=INT_MAX;
                if(j>0) up_left=matrix[i-1][j-1];
                if(j<m-1) up_right=matrix[i-1][j+1];
                up=matrix[i-1][j];
                matrix[i][j]=matrix[i][j]+min(up,min(up_left,up_right));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,matrix[n-1][i]);
        }
        return ans;
    }
};

