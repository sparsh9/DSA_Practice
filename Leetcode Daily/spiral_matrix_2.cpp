class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0){
            return {};
        }
        int size = n*n;
        vector<vector<int>> m(n,vector<int>(n));
        // vector<vector<int>> m(n, vector<int>(n, 0));
        int left = 0, top = 0;
        int right = n-1, bottom = n-1;
        int k=1;
        while(left <= right && top <= bottom){
            // Iterating over top row
            for(int i = left ; i<=right ; i++){
                m[top][i] = k;
                k++;
            }
            top++;
            // Iterating over right col
            for(int i=top;i<=bottom;i++){
                m[i][right] = k;
                k++;
            }
            right--;
            // Iterating over bottom row
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    m[bottom][i] = k;
                    k++;
                }
                bottom--;
            }
            // Iterating over left col
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    m[i][left] = k;
                    k++;
                }
                left++;
            }
        }
        return m;
    }
};