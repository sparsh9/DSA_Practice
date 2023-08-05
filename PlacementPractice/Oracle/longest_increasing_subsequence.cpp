// Approach :Recursion + Memoization

int helper(int ind,int prev_ind, int n,vector<int> &nums, vector<vector<int>> dp){
    // base case

    // out of bounds
    if(ind == n)
        return 0;

    // check previous calculations
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

    int len =0;
    // not take
    dp[ind][prev_ind+1] = 0 + helper(ind+1,prev_ind+1,n,nums,dp);
    // take
    if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
        dp[ind][prev_ind+1] = max(dp[ind][prev_ind+1], 1 + helper(ind+1,ind,n,nums,dp)); // maximum of take and not take
    }
    return dp[ind][prev_ind+1] = len;
}


int findLIS(vector<int> &nums){
    int n = nums.size();

    vector<vector<int>> dp(n,vector<int>(n+1,-1)); // right shifting the prev_ind to 1 place to store -1 as well

    return helper(0,-1,n,nums,dp);

}





// Approach : Tabulation

int findLIS(vector<int> &nums){
    int n = nums.size();

    vector<vector<int>> dp(n+1,vector<int>(n+1,0)); // right shifting the prev_ind to 1 place to store -1 as well

    // because it is tabulation, therefore reverse all the logic as done in recusion part
    for(int ind = n-1;ind>=0;ind--){
        for(int prev = n-1;prev>= -1;prev--){
            // not take
            int len = 0 + dp[ind+1][prev+1]; // as here we are accessing dp[ind+1] but we made till n-1 only, so we need to have dp(n+1)*(n+1)
            // take
            if(prev == -1 || nums[ind] > nums[prev]){
                len = max(len, 1+dp[ind+1,ind+1]); // here actually prev = ind + 1 but since we have right shift position of 1, therefore adding the 1 extra
            }
        }
    }

}




