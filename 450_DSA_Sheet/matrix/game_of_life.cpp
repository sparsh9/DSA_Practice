// Problem Link: https://leetcode.com/problems/game-of-life/

class Solution {
public:

    // Function to check if the cell is valid
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    // Function to count the live cells in the neighborhood
    int countLiveNeighbors(int i, int j, vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        
        // Define the eight possible directions
        int dirX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dirY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int k = 0; k < 8; k++) {
            int ni = i + dirX[k];
            int nj = j + dirY[k];
            
            if (isValid(ni, nj, m, n) && board[ni][nj] == 1){
                count++;
            }
        }
        
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp = board; 
        // we are using a temp array to store the original values of the board
        // so that all the changes made to original board is according to its intial state and 
        // represents only 1 state change and not iterative

        // Iterate through the entire board and calculate the number of live neighbors for each cell
        // Update the cells based on the rules of the Game of Life
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int live = countLiveNeighbors(i, j, temp);

                if (board[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = 2; // Mark it as 2 to indicate that it was live but will die
                } else {
                    if (live == 3)
                        board[i][j] = 3; // Mark it as 3 to indicate that it was dead but will come to life
                }
            }
        }

        // Now update the board based on the marked cells (2 and 3)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};