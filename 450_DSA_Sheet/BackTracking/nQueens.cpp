class Solution {
public:
    bool isSafe(int n, vector<string>& nQueens, int row, int col){
        // checking along with column
        for(int i=0; i<n; i++){
            if(nQueens[i][col] == 'Q'){
                return false;
            }
        }
        // checking along the diagonal 1
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(nQueens[i][j] == 'Q'){
                return false;
            }
        }
        // checking along diagonal 2
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(nQueens[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void helper(int n, vector<vector<string>>& output, vector<string>& nQueens, int row){
        if(row == n){
            output.push_back(nQueens);
            return;
        }
        for(int col=0; col<n; col++){
            if(isSafe(n, nQueens, row, col)){
                nQueens[row][col] = 'Q';
                helper(n, output, nQueens, row+1); // har row mein ek baar hi daal rahe hai isse, toh row ko check karne hi zarurat nahi hai
                // backtrack karte waqt wapas reset kardo isko
                nQueens[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> nQueens(n , string(n, '.'));
        helper(n, output, nQueens, 0);
        return output;
    }
};