// Approach 1 (Using simple bfs approach)
// Bfs works here bcz edge weights are 1
class Solution {
    bool isSafe(int x, int y, int m, int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    vector<vector<int>> directions = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1},{1,0},{1,1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==0 || n==0 || grid[0][0] != 0)
            return -1;
        
        queue<pair<int,int>> pq;
        pq.push({0,0}); // Initially push the start node
        grid[0][0] = 1; // Mark this node as visited

        int level = 0;

        while(!pq.empty()){
            int N = pq.size();

            while(N--){
                auto curr = pq.front();
                pq.pop();

                if(curr.first == m-1 && curr.second == n-1)
                    return level+1;
                
                for(auto dir : directions){
                    int x = curr.first + dir[0];
                    int y = curr.second + dir[1];

                    if(isSafe(x,y,m,n) && grid[x][y] == 0){
                        pq.push({x,y});
                        grid[x][y] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

// Approach 2 (Using Dijkstra's Algorithm)
// Here the result vector will be a 2D vector of pairs unlike the 1D vector of pairs in Dijkstra's Algorithm

class Solution {
    typedef pair<int,pair<int,int>> p;
    bool isSafe(int x, int y, int m, int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    vector<vector<int>> directions = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1},{1,0},{1,1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==0 || n==0 || grid[0][0] != 0)
            return -1;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX)); // Initiating a 2D result matrix with all values as INT_MAX(infinity)
        priority_queue<p,vector<p>,greater<p>> pq; // Initiating a min heap priority queue as (distance, (x,y))

        pq.push({0,{0,0}}); // Initially push the start node
        result[0][0] = 0; // Mark the distance of start node as 0

        while(!pq.empty()){
            int d = pq.top().first;
            pair<int,int> node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            for(auto dir : directions){
                int i = x + dir[0];
                int j = y + dir[1];

                if(isSafe(i,j,m,n) && grid[i][j] == 0 && d+1 < result[i][j]){ // 1 is the distance between two nodes
                    result[i][j] = d+1;
                    pq.push({d+1,{i,j}});
                }
            }
        }
        return result[m-1][n-1] == INT_MAX ? -1 : result[m-1][n-1]+1; 
        // if the distance of the end node is infinity, return -1 else return the distance
        // +1 is added bcz we have only calculated steps between two nodes and not the total nodes traversed

    }
};