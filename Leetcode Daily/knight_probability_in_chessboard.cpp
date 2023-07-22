// Approach (Using Tabulation)
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // dp[i][j] = probability of being on cell (i, j) after k moves
        vector<vector<double>> dp(n, vector<double>(n, 0));
        // base case
        dp[row][column] = 1;

        // all possible moves
        vector<vector<int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

        for (int move = 1; move <= k; move++) {
            vector<vector<double>> newDp(n, vector<double>(n, 0));
            for (int row = 0; row < n; row++) {
                for (int column = 0; column < n; column++) {
                    // for each cell, find the probability of being on that cell after k moves
                    for (const auto& m : moves) {
                        int newR = row + m[0]; // newR = new row
                        int newC = column + m[1]; // newC = new column
                        if (isValid(newR, newC, n)) {
                            // probability of being on cell (row, column) after k moves
                            newDp[row][column] += dp[newR][newC] / 8.0; // 8.0 = number of possible moves
                        }
                    }
                }
            }
            // update dp
            dp = newDp;
        }

        double probability = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                // add all probabilities
                probability += dp[r][c];
            }
        }

        return probability;
    }

    bool isValid(int r, int c, int n) {
        // check if cell (r, c) is valid or not
        // cell is valid if it is inside the board
        // i.e. r and c are in the range [0, n)
        return r >= 0 && r < n && c >= 0 && c < n;
    }
};