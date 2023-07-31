// Approach 1 (Using even odd sum concept)
// As no 2 houses can be robbed, therefore every adjacent houses will be summed differently
class Solution {
public:
    int rob(vector<int>& nums) {
        int even_sum = 0; // Sum of even-indexed elements
        int odd_sum = 0; // Sum of odd-indexed elements

        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                even_sum = max(even_sum + nums[i], odd_sum);
            } else {
                odd_sum = max(odd_sum + nums[i], even_sum);
            }
        }

        return max(even_sum, odd_sum);
    }
};



// Approach 2 (Using Recursion)

class Solution {
public:
    int helper(int i, vector<int> &nums){
        // base case
        if (i == 0)
            return nums[i];
        // out of bounds
        if (i < 0)
            return 0;
        
        int pick = nums[i] + helper(i - 2, nums);

        int nonPick = 0 + helper(i - 1, nums);

        return max(pick, nonPick);
    }
    int rob(vector<int> &nums){
        int n = nums.size();
        return helper(n-1, nums);
    }
};



// Approach 3 (Using Recursion + Memoization)

class Solution {
public:
    int helper(int i, vector<int> &nums, vector<int> &dp){
        // base case
        if (i == 0)
            return dp[i] = nums[i];
        // out of bounds
        if (i < 0)
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int pick = nums[i] + helper(i - 2, nums, dp);

        int nonPick = 0 + helper(i - 1, nums, dp);

        return dp[i] = max(pick, nonPick);
    }
    int rob(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(n-1, nums, dp);
    }
};