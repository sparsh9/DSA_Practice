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


        if(m.empty()) return ans;
        // dfs traversals for pacific and atlantic along the top and bottom edges.
        for(int i=0;i<m;i++){
            dfs(heights,i,0,dp,1,0,ans);
            dfs(heights,i,n-1,dp,2,0,ans);
        }
        // dfs traversals for pacific and atlantic along the left and right edges.
        for(int i=0;i<n;i++){
            dfs(heights,0,i,dp,1,0,ans);
            dfs(heights,m-1,i,dp,2,0,ans);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (dp[i * n + j] == 3) 
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
    
    void dfs(vector<vector<int>>& heights,int i,int j,vector<int>& dp,int w,int h,vector<vector<int>>& ans){
        int m= heights.size(),n=heights[0].size();
        int ij=i*n+j;
        if(i<0||i>=m||j<0||j>=n||heights[i][j]==0) return;
        if((dp[ij] & w) || heights[i][j]<h) return;
        dp[ij] += w;
        h=heights[i][j];
        // if(dp[ij]==3) ans.push_back({i,j});


        if((i+1)<m) dfs(heights,i+1,j,dp,w,h,ans); // Next Column
        if(i>0) dfs(heights,i-1,j,dp,w,h,ans); // Previous Column
        if((j+1)<n) dfs(heights,i,j+1,dp,w,h,ans); // Next Row
        if(j>0) dfs(heights,i,j-1,dp,w,h,ans); // Previous Row
    }
};