class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n=m ? grid[0].size() : 0 , islands =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                islands++;
                markIsland(grid,i,j);
                }
            }
        }
        return islands;
    }
    
private:
    
    void markIsland(vector<vector<char>>& grid,int i,int j){
        int m = grid.size(),n=grid[0].size();
        // jab tak paani nahi milta ya out of bounds nahi hota tab tak chalte raho
        // jaisi kuch mile toh turant return kar do
        if(i<0 || i==m || j<0 || j==n || grid[i][j]=='0'){
           return; 
        }

        // jab tak island mil raha hai tab tak usko 0 mark karo(island mark karte jao)
        grid[i][j] = '0';
        markIsland(grid,i+1,j);
        markIsland(grid,i-1,j);
        markIsland(grid,i,j+1);
        markIsland(grid,i,j-1);
    }
};


