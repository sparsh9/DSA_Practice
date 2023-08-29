class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // 1. Transpose the matrix
        for (int row = 0; row < m; row++){
            for (int col = row; col < n; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // 2. Reverse each row
        for (int row = 0; row < m; row++){
            reverse(matrix[row].begin(), matrix[row].end());
        }

        return;
    }
};