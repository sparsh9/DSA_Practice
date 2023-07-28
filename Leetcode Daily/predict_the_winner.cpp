// This is a part of Optimal Game Strategy
// Here we have to find whether the first player can win or not
// To solve this question, keep in mind below points :
// 1. If it's your turn, then give your best (Maximum)
// 2. When it's your opponent's turn, expect worst from him as he might also have chosen his best (Minimum)


// Approach 1: Recursion
class Solution {
    int helper(int left, int right, vector<int>& nums){
        // out of bounds
        if(left > right)
            return 0;
        // only one element
        if(left == right)
            return nums[left];

        // here we are only calculating the score of player 1, so skipping the score of player 2
        // as player 2 will also play optimally and will choose his best move
        int pick_left = nums[left] + min(helper(left+2,right,nums), helper(left+1,right-1,nums));
        int pick_right = nums[right] + min(helper(left+1,right-1,nums), helper(left,right-2,nums));

        return max(pick_left, pick_right);
    }


public:
    bool PredictTheWinner(vector<int>& nums) {
        int total_score = accumulate(nums.begin(), nums.end(), 0);

        int player1_score = helper(0,nums.size()-1,nums);

        int player2_score = total_score - player1_score;

        return player1_score >= player2_score;
    }
};


// Approach 2: Recursion + Memoization

class Solution {
    public:
    int helper(int left, int right, vector<int>& nums, vector<vector<int>>& dp){
        // out of bounds
        if(left > right)
            return 0;
        // only one element
        if(left == right)
            return nums[left];

        if(dp[left][right] != -1)
            return dp[left][right];

        // here we are only calculating the score of player 1, so skipping the score of player 2
        // as player 2 will also play optimally and will choose his best move
        int pick_left = nums[left] + min(helper(left+2,right,nums,dp), helper(left+1,right-1,nums,dp));
        int pick_right = nums[right] + min(helper(left+1,right-1,nums,dp), helper(left,right-2,nums,dp));

        return dp[left][right] = max(pick_left, pick_right);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int total_score = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        int player1_score = helper(0,nums.size()-1,nums,dp);

        int player2_score = total_score - player1_score;

        return player1_score >= player2_score;
    }
};


// Approach 3 : Tabulation

class Solution {
    public:
    bool PredictTheWinner(vector<int>& nums) {
        int total_score = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        for(int i=0; i<nums.size(); i++)
            dp[i][i] = nums[i];

        for(int len=2; len<=nums.size(); len++){
            for(int i=0; i<=nums.size()-len; i++){
                int j = i+len-1;
                int pick_left = nums[i] + min(dp[i+2][j], dp[i+1][j-1]);
                int pick_right = nums[j] + min(dp[i+1][j-1], dp[i][j-2]);

                dp[i][j] = max(pick_left, pick_right);
            }
        }

        int player1_score = dp[0][nums.size()-1];

        int player2_score = total_score - player1_score;

        return player1_score >= player2_score;
    }
};

