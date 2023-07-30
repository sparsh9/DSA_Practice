// Refer this link for reference of explaination
// https://leetcode.com/problems/perfect-squares/solutions/1520447/c-dp-easy-to-understand/

class Solution {
public:
    int numSquares(int n) {
        // Create a vector to store the minimum number of squares required to reach each number from 0 to n.
        vector<int> dp(n+1, INT_MAX);
        
        // Base case: To reach 0, we need 0 squares.
        dp[0] = 0; 
        
        // Start with the first perfect square, i.e., 1.
        int count = 1;
        
        // Loop until count*count is less than or equal to n.
        while (count*count <= n) {
            int sq = count*count; // Calculate the square of the current number.
            
            // Update the dp array from the current square to n.
            // For each number i, update dp[i] by taking the minimum of the current value of dp[i]
            // and dp[i-sq] + 1, where dp[i-sq] represents the minimum number of squares required to reach i-sq
            // and +1 accounts for taking the current square into consideration.
            for (int i = sq; i < n+1; i++) {
                dp[i] = min(dp[i-sq] + 1, dp[i]); // Here we have added "+1" bcz the dp stores the number of 
                                                    // perfect squares required to reach that number, so when we subtract 'i-sq'
                                                    // we have that 'sq' wala number.
            }
            
            // Increment count to consider the next perfect square.
            count++;
        }
        
        // The value at dp[n] will represent the minimum number of squares required to reach n.
        return dp[n];
    }
};
