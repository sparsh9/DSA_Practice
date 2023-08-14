// Approach (Recursion + Memoization)
class Solution {
public:
    bool validPrefix(int index, vector<int> &nums, vector<int> &dp){
        if (index < 0)
            return 1; //Empty subarray case
        if (dp[index] != -1)
            return dp[index]; //Already solved
        bool twoIdentical = 0;
        bool threeIdentical = 0;
        bool increasingSeq = 0;
        
        // if 2 are equal
        if (index > 0 && nums[index] == nums[index - 1])
            twoIdentical = validPrefix(index - 2, nums, dp);
        //  3 are equal
        if (index > 1 && nums[index] == nums[index - 1] && nums[index - 1] == nums[index - 2])
            threeIdentical = validPrefix(index - 3, nums, dp);
        // increasing sequence
        if (index > 1 && nums[index] == nums[index - 1] + 1 && nums[index - 1] == nums[index - 2] + 1)
            increasingSeq = validPrefix(index - 3, nums, dp);
        return dp[index] = twoIdentical || threeIdentical || increasingSeq;
    }
    bool validPartition(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, -1);
        return validPrefix(n - 1, nums, dp); //Check if the whole array is valid
    }
};



// Approach (Tabulation)

class Solution {
public:
    bool validPartition(vector<int> &nums){
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        dp[0] = 1;//Emprt subarray case

        for (int index = 0; index < n; index++)
        {
            int i = index + 1;
            bool twoIdentical = false;
            bool threeIdentical = false;
            bool increasingSeq = false;

            // if 2 are equal
            if (index > 0 && nums[index] == nums[index - 1])
            {
                twoIdentical = dp[i - 2];
            }
            // 3 are equal
            if (index > 1 && nums[index] == nums[index - 1] && nums[index - 1] == nums[index - 2] && nums[index] == nums[index - 2])
            {
                threeIdentical = dp[i - 3];
            }
            // increasing sequence
            if (index > 1 && nums[index] == nums[index - 1] + 1 && nums[index - 1] == nums[index - 2] + 1)
            {
                increasingSeq = dp[i - 3];
            }

            dp[i] = twoIdentical || threeIdentical || increasingSeq;
        }

        return dp[n];
    }
};