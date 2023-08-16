// Using BFS

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();    
        int time = 0;

        // row, col, time
        queue<array<int, 3>> q;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2)
                    q.push({r, c, 0}); // initially time is 0
            }
        }

        int DIR[][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

        while (!q.empty()) {
            int r = q.front()[0];
            int c = q.front()[1];
            int t = q.front()[2];
            q.pop();

            time = max(time, t); // we took the max time of the rotten oranges because we have to return the time when all the oranges are rotten

            for (int i = 0; i < 4; i++) { // 4 directions possible
                int nr = r + DIR[i][0], nc = c + DIR[i][1]; // nr -> new row, nc -> new col
                if (nr < 0 || nc < 0 || nr == m || nc == n || grid[nr][nc] != 1)
                    continue; // out of bounds indexes
                // make the 4 dimensionally connected oranges as rotten
                grid[nr][nc] = 2; // rotten
                // push the rotten orange into the queue as we will start from these oranges as initial points
                q.push({nr, nc, t + 1});
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) // if there is any fresh orange left even after the BFS, then return -1
                    return -1;
            }
        }

        return time; 
    }
};