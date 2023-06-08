// Solution Video Link : https://www.youtube.com/watch?v=MMr19RE7KYY 

class Solution {
public:
    // Optimal Approach 1 (Using Memoization)


    //  int memoization(vector<vector<char>>& matrix) {
    //     if (matrix.empty()) return 0;
    //     vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), -1));
        
    //     int res = 0;
    //     for(int i = 0; i < matrix.size(); ++i) {
    //         for(int j = 0; j < matrix[0].size(); ++j) {
    //             res = max(res, solve(matrix, mem, i, j));
    //         }
    //     }
    //     return res * res;
    // }
    
    // int solve(vector<vector<char>>& matrix, vector<vector<int>>& mem, int i, int j) {
    //     if (i >= matrix.size() || j >= matrix[0].size()) return 0;
    //     if (mem[i][j] >= 0) return mem[i][j];
    //     if (matrix[i][j] == '0') return mem[i][j] = 0;
    //     mem[i][j] = min(min(solve(matrix, mem, i+1, j), solve(matrix, mem, i, j+1)),
    //                     solve(matrix, mem, i+1, j+1)) + 1;
    //     return mem[i][j];
    // }




    // Optimal Approach 2 (using Tabulation)


    int tabulation(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int res = 0;
        vector<vector<int>> tab(matrix.size(), vector<int>(matrix[0].size()));

        for(int row = tab.size() - 1; row >= 0; --row) {
            for(int col = tab[0].size() - 1; col >= 0; --col) {
                if (col == matrix[0].size() - 1) {
                    tab[row][col] = matrix[row][col] == '0' ? 0 : 1;
                } else if (row == matrix.size() - 1) {
                    tab[row][col] = matrix[row][col] == '0' ? 0 : 1;
                } else if (matrix[row][col] == '0') {
                    tab[row][col] = 0;
                } else {
                    tab[row][col] = min(min(tab[row+1][col], tab[row][col+1]),
                                        tab[row+1][col+1]) + 1;
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