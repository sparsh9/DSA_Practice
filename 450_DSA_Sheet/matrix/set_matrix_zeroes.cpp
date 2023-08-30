// Approach : Using extra space for row and col array to get the respective 
// row and col for the element == 0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowsArray(m, 1);
        vector<int> colsArray(n, 1);

        // get respective row and col
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowsArray[i] = 0;
                    colsArray[j] = 0;
                }
            }
        }

        // now make all elements of that row and col as 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rowsArray[i] == 0 || colsArray[j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
};




// Approach : Using Constact Space Time: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool isCol = false;

        // get respective row and col
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                isCol = true;

            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // mark the first element of that row and col as 0
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // now make all elements of that row and col as 0
        // except the first element of that row and col
        // because that will be used to mark the row and col as 0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        }

        // check if the first row needs to be set to zero
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // check if the first col needs to be set to zero
        if (isCol) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }

        return;
    }
};

