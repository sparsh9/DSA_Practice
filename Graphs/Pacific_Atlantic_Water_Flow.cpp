class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m=heights.size(),n=heights[0].size();
        vector<int> dp(m*n);
        // Initializing the dp 1d array to zero for every cell.
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i*n+j] = 0;


        if(m<1) return ans;
        for
        for(int i=0;i<m;i++){
            dfs(heights,i,0,dp,w,ans);
            dfs(heights,i,n-1,dp,w,ans);
        }
        for(int i=0;i<n;i++){
            dfs(heights,0,i,dp,w,ans);
            dfs(heights,m-1,dp,i,w,ans);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
            }
        }

        return ans;
    }
    
    void dfs(vector<vector<int>>& heights,int i,int j,vector<int>& dp,int w,int h,vector<vector<int>>& ans){
        if(i<0||i>=m||j<0||j>=n||heights[i][j]==0) return;
        if((dp[ij] & w) || heights[i][j]<h) return;
        


        dfs(heights,i+1,j,w,ans); // Next Column
        dfs(heights,i-1,j,w,ans); // Previous Column
        dfs(heights,i,j+1,w,ans); // Next Row
        dfs(heights,i,j-1,w,ans); // Previous Row
    }
};