// Approach (Using BFS Traversal)
// Intially we are marking all the 0's present in the original matrix as 0 in the distance matrix, 
// as distance from that 0 to nearest 0 will be 0 only
// Now we will move level wise, like calculating all the distance from the adjacent cells of these initial 0's
// the distance will be 0 + level
// like for level 1  -> steps = 0+1
// for level 2  -> steps = 0+1+1
// and similarly till the index is out of bound
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
	    int m=grid[0].size();
        // visited matrix 
	    vector<vector<bool>> vis(n,vector<bool>(m,false));
        // distance matrix to be returned as answer 
	    vector<vector<int>> dis(n,vector<int>(m,0));
        // queue for bfs traversal q((row,col),steps/distance)
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
                // Initially pushing all the indexes with value as 0
	            if(grid[i][j]==0)
	            {
                    // distance from 0 to nearest 0 will be 0 itself
	                q.push({{i,j},0});
	                vis[i][j]=true;
	            }
	        }
	    }
        // for traversal along the 4-directions
	    int dr[]={-1,1,0,0};
	    int dc[]={0,0,-1,1};
	    while(!q.empty())
	    {
	        auto it=q.front();
	        int row=it.first.first;
	        int col=it.first.second;
	        int st=it.second;
	        q.pop();
            // marking the steps as distance to the distance matrix
	        dis[row][col]=st;
	        
	        for(int i=0;i<4;i++)
	        {
	            int nrow=row+dr[i];
	            int ncol=col+dc[i];
                // checking the validity of the index we are at
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]!=0)
	            {
                    // marking as visited
	                vis[nrow][ncol]=true;
                    // pushing to the queue
	                q.push({{nrow,ncol},st+1});
	            }
	        }
	        
	    }
	    return dis;
    }
};