// Approach 1 (Using Recursion)

bool helper(int n, int k, vector<int> &arr) {
    if(k == 0) return true;
    if(n < 0) return false;
    if(arr[n] <= k) {
        bool take = helper(n-1,k-arr[n],arr); // target is reduced by arr[n]
        bool notTake = helper(n-1,k,arr); // target remains same
        return take || notTake;
    }
    return helper(n-1,k,arr);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return helper(n-1,k,arr);
}


// Approach 2 (Using Memoization)

bool helper(int n, int k, vector<int> &arr, vector<vector<int>> &dp) {
    // base case for index = 0
    if(n == 0) return dp[n][k] = target; // when there is only one element, we can make target only if it is equal to the element
    // base case for target = 0
    if(k == 0) return dp[n][k] = true; // whenever target is 0, we can always make it with this or any element, hence all are true

    if(dp[n][k] != -1) return dp[n][k];

    bool notTake = helper(n-1,k,arr,dp); // target remains same
    bool take = false;
    if(arr[n] <= k)
        take = helper(n-1,k-arr[n],arr,dp); // target is reduced by arr[n]

    return dp[n][k] = take || notTake;
    // so here ultimately, we are forming a matrix such that for every target k,
    // we get the True or False value for every index n
    // which signifies whether we take the element at that index or not in our subset equal to target k
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1)); // we took k+1 because we have to store the result for k = 0 to k = k
    return helper(n-1,k,arr,dp);
}


// Approach 3 (Using Tabulation)

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));

    // base case
    for(int i = 0; i < n; i++) dp[i][0] = true; // when target is 0, we can always make it by not taking any element

    // when the index is 0 and the target is equal to the element at that index
    // then we can mark it as true
    dp[0][arr[0]] = true; 

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            bool notTake = dp[i-1][j]; // target remains same
            bool take = false;
            if(arr[i] <= j)
                take = dp[i-1][j-arr[i]]; // target is reduced by arr[n]
            dp[i][j] = take || notTake;
        }
    }
    return dp[n-1][k];
}