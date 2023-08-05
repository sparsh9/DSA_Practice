// Here it is a case of take and not take, just here in the case of take,
// we will first check if the current element is greater than the previous element and if it is then only we will take it.



// Approach : Recursion

class Solution {
public:
    int helper(int ind, vector<int> &nums, int n, int prev_ind){
        // out of bound
        if(ind == n) return 0;

        // not take
        int len = 0 + helper(ind+1,nums,n,prev_ind);

        // take
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len, 1 + helper(ind+1,nums,n,ind));
        }

        return len;
    }


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        return helper(0,nums,n,-1);
    }
};




// Approach : Recursion + Memoization

class Solution {
public:
    int helper(int ind, vector<int> &nums, int n, int prev_ind, vector<vector<int>> &dp){
        // out of bound
        if(ind == n) return 0;

        
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        // not take
        int len = 0 + helper(ind+1,nums,n,prev_ind,dp);

        // take
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len, 1 + helper(ind+1,nums,n,ind,dp));
        }

        return dp[ind][prev_ind+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // here we took n+1 because we have to store the prev_ind value also
        // and as we cannot store -1 index in the vector, therefore we did a coordinate shift of 1 to right
        // so  -1 -> 0 and 0 -> 1 and so on

        // similarly we are also passing prev_ind+1 in the helper function instead of prev_ind

        return helper(0,nums,n,-1,dp);
    }
};




// Approach : Tabulation

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // here we also took n+1 in the outer vector as ind = n-1 and 
        // we are accessing ind+1 which is n and for vector of n size, n is not possible, 
        // hence it's size is increased

        for(int ind = n-1;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){
                // not take
                int len = 0 + dp[ind+1][prev_ind+1];

                // take
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + dp[ind+1][ind+1]);
                }

                dp[ind][prev_ind+1] = len;
            }
        }

        return dp[0][-1+1];
    }
};



// Approach : Tabulation (Optimized)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);

        for(int ind = n-1;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){
                // not take
                int len = 0 + curr[prev_ind+1];

                // take
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + next[ind+1]);
                }

                curr[prev_ind+1] = len;
            }
            next = curr;
        }

        return curr[-1+1];
    }
};