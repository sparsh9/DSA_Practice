// Approach (Using Binary Search on 2D Matrix)
class Solution {
public:
    // Part 1 of the Solution
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
            } 
            else {
                i--;
            }
        }
        return count;
    }


    // Part 2 of the solution
    // In this element, as we got to know that how many numbers are less or equal to a target,
    // Which means we get the kth element in the matrix
    // Therefore to get the kth smallest element, we will now apply the binary search on the Ranks of elements in the matrix

    // Here Rank of Element in matrix is : count of elements in the 2D matrix which are smaller or equal to the element

    // So, if the rank matches to the k, therefore we get the answer
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), i = matrix[0][0], j = matrix[n-1][n-1];
        while(i < j){
            int mid = i + (j-i)/2;
            int rank = countLessThanEqualtoElements(matrix, mid);
            if(rank < k) i = mid+1;
            else j = mid;
        }
        return i;
    }

};