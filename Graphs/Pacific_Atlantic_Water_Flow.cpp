// Leetcod problem of Pacific Atlantic Water Flow

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
    vector<vector<int>> res;
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> pacific(m,vector<int>(n,0));
    vector<vector<int>> atlantic(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        dfs(heights,i,0,pacific);
        dfs(heights,i,n-1,atlantic);
    }
    for(int j=0;j<n;j++){
        dfs(heights,0,j,pacific);
        dfs(heights,m-1,j,atlantic);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pacific[i][j]==1 && atlantic[i][j]==1){
                res.push_back({i,j});
            }
        }
    }
    return res;
}