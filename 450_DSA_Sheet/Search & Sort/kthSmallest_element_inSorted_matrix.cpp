
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), i = matrix[0][0], j = matrix[n-1][n-1];
        while(i < j){
            int mid = i + (j-i)/2;
            int posi = countLessThanEqualtoElements(matrix, mid);
            if(posi < k) i = mid+1;
            else j = mid;
        }
        return i;
    }
    // This helper function counts the total number of elements 
    // which are less or than equal to the target element in a sorted matrix
    // Refer the Search in 2D Matrix leetcode problem for more clarity
    int countLessThanEqualtoElements(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int i = n - 1, j = 0, count = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                count += (i + 1);
                j++;
            } else {
                i--;
            }
        }
        return count;
    }
};