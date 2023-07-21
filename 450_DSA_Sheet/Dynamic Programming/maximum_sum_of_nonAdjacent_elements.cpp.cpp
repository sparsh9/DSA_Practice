// Approach 1: Normal Recursion
// In this approach, we use simple recursive calls to find the maximum sum of non-adjacent elements.

int maxSumNonAdjacent(int i, vector<int>& nums) {
    // Base case: If there are no elements left, the sum is 0.
    if (i < 0) {
        return 0;
    }

    // Recursive case:
    // Either include the current element and skip the adjacent element,
    // or skip the current element and move to the next element.
    return max(maxSumNonAdjacent(i - 2, nums) + nums[i], maxSumNonAdjacent(i - 1, nums) + 0);
}

int maxSumNonAdjacent(vector<int>& nums) {
    return maxSumNonAdjacent(nums.size() - 1, nums);
}




// Approach 2: Recursion + Memoization
// In this approach, we use recursion along with memoization to avoid redundant calculations.

int maxSumNonAdjacentUtil(int i, vector<int>& nums, vector<int>& memo) {
    if (i < 0) {
        return 0;
    }

    if (memo[i] != -1) {
        return memo[i];
    }

    int includeCurrent = maxSumNonAdjacentUtil(i - 2, nums, memo) + nums[i];
    int skipCurrent = maxSumNonAdjacentUtil(i - 1, nums, memo) + 0;

    memo[i] = max(includeCurrent, skipCurrent);
    return memo[i];
}

int maxSumNonAdjacent(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return maxSumNonAdjacentUtil(nums.size() - 1, nums, memo);
}




// Approach 3: Tabulation
// In this approach, we use tabulation (bottom-up) to fill the DP table and find the maximum sum of non-adjacent elements.

int maxSumNonAdjacent(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
        // Calculate the maximum sum with the current element (nums[i]) and without the current element (dp[i-1]).
        dp[i] = max(nums[i] + (i >= 2 ? dp[i - 2] : 0), dp[i - 1]);
    }

    return dp[n - 1];
}


// Approach 4: Space Optimization
// In this approach, we use space optimization to reduce the space complexity to O(1).

int maxSumNonAdjacent(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    int prevInclude = nums[0];
    int prevSkip = 0;

    for (int i = 1; i < n; i++) {
        // Calculate the maximum sum with the current element (nums[i]) and without the current element (prevInclude).
        int currInclude = nums[i] + prevSkip;
        int currSkip = max(prevInclude, prevSkip);

        prevInclude = currInclude;
        prevSkip = currSkip;
    }

    return max(prevInclude, prevSkip);
}



