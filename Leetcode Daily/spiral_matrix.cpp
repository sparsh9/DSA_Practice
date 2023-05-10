class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> result;
        if(matrix.empty() || matrix[0].empty()){
            return result;
        }

        int top = 0, left=0, bottom=rows-1, right = cols-1;
        while(left <= right && top <= bottom){
            // Iterating over top row
            for(int i=left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            // Iterating over right column
            for(int i=top;i<=bottom;i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            // Iterating over bottom row
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // Iterating over left column
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

        }
        return result;
    }
};