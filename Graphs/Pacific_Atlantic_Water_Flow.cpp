class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m=heights.size(),n=heights[0].size();
        vector<char> dp(m*n);
        if(m<1) return ans;
        for(int i=0;i<m;i++){
            dfs(heights,i,0,dp,m,n,ans);
            dfs(heights,i,n-1,dp,m,n,ans);
        }
        for(int i=0;i<n;i++){
            dfs(heights,0,i,dp,m,n,ans);
            dfs(heights,m-1,dp,i,m,n,ans);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
            }
        }

        return ans;
    }
    
    void dfs(vector<vector<int>>& heights,int i,int j,vector<int>& dp,int m,int n,vector<vector<int>>& ans){
        if(i<0||i>=m||j<0||j>=n||heights[i][j]==0) return;



        dfs(heights,i+1,j,m,n,ans);
        dfs(heights,i-1,j,m,n,ans);
        dfs(heights,i,j+1,m,n,ans);
        dfs(heights,i,j-1,m,n,ans);
    }
};