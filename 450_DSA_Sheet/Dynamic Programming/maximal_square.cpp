// Solution Video Link : https://www.youtube.com/watch?v=MMr19RE7KYY 

class Solution {
public:
    // // Optimal Approach 1 (Using Memoization)
    // // Here we are going from the top left to bottom right corner


    // int memoization(vector<vector<char>>& matrix) {
    //     if (matrix.empty()) return 0;
    //     vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), -1));
        
    //     int res = 0;
    //     for(int i = 0; i < matrix.size(); ++i) {
    //         for(int j = 0; j < matrix[0].size(); ++j) {
    //             res = max(res, solve(matrix, mem, i, j)); 
    //             // check for every index of the matrix and see how many size square is possible from that
    //         }
    //     }
    //     return res * res;
    // }
    
    // int solve(vector<vector<char>>& matrix, vector<vector<int>>& mem, int i, int j) {
    //     if (i >= matrix.size() || j >= matrix[0].size()) return 0;
    //     if (mem[i][j] >= 0) return mem[i][j];
    //     if (matrix[i][j] == '0') return mem[i][j] = 0;
        
    //     // we try to see that what is the size of square possible from current i,j in the right, down and diagonal direction
    //     // then we take the min of all the three and add 1 to it
    //     int right = solve(matrix, mem, i, j+1);
    //     int down = solve(matrix, mem, i+1, j);
    //     int diag = solve(matrix, mem, i+1, j+1);

    //     mem[i][j] = 1 + min(min(right, down), diag); // we try to get the minimum of three
    //     return mem[i][j];
    // }




    // Optimal Approach 2 (using Tabulation)


    int tabulation(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int res = 0;
        vector<vector<int>> tab(matrix.size(), vector<int>(matrix[0].size()));

        // iterating to every index of the matrix and checking how many size square is possible from that
        for(int row = tab.size() - 1; row >= 0; --row) {
            for(int col = tab[0].size() - 1; col >= 0; --col) {
                // Base Case : if either row or column reaches maximum
                if (col == matrix[0].size() - 1 or row == matrix.size() - 1) {
                    tab[row][col] = matrix[row][col] == '0' ? 0 : 1;
                    // if the current index is 1 then we can make a square of size 1
                } 
                else if (matrix[row][col] == '0') {
                    tab[row][col] = 0; // not possible at all
                } else {
                    int right = tab[row][col+1];
                    int down = tab[row+1][col];
                    int diag = tab[row+1][col+1];

                    tab[row][col] = 1 + min(min(right, down), diag);
                }
                res = max(res, tab[row][col]);
            }
        }
        
        return res * res;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // return memoization(matrix);
        return tabulation(matrix);
    }
};