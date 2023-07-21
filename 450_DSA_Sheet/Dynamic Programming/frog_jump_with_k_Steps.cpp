// Here instead of fixed number of 2 steps, the frog now can take variable number 
// of steps from 1 to k so to handle this we will simple run a for loop for k steps in the dp approach




// Approach 1: Normal Recursion
// In this approach, we use simple recursive calls to find the minimum energy required to reach the nth stair.

int jumpFrog(int n, int k, vector<int>& heights) {
    // Base case: If we are at the topmost stair (nth stair), no energy is required.
    if (n == 1) {
        return 0;
    }

    // Initialize the minimum energy required to a large value.
    int minEnergy = INT_MAX;

    // Try all possible steps from 1 to k.
    for (int i = 1; i <= k && n - i >= 1; i++) {
        // Calculate the energy required to reach the (n-i)th stair recursively.
        int energy = jumpFrog(n - i, k, heights);

        // Calculate the total energy required to reach the nth stair from the (n-i)th stair.
        energy += abs(heights[n - 1] - heights[n - 1 - i]);

        // Update the minimum energy if the current energy is smaller.
        minEnergy = min(minEnergy, energy);
    }

    return minEnergy;
}




// Approach 2: Recursion + Memoization
// In this approach, we use recursion along with memoization to avoid redundant calculations.

int jumpFrogUtil(int n, int k, vector<int>& heights, vector<int>& memo) {
    if (n == 1) {
        return 0;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    int minEnergy = INT_MAX;

    for (int i = 1; i <= k && n - i >= 1; i++) {
        int energy = jumpFrogUtil(n - i, k, heights, memo);
        energy += abs(heights[n - 1] - heights[n - 1 - i]);
        minEnergy = min(minEnergy, energy);
    }

    memo[n] = minEnergy;
    return minEnergy;
}

int jumpFrog(int n, int k, vector<int>& heights) {
    vector<int> memo(n + 1, -1);
    return jumpFrogUtil(n, k, heights, memo);
}



// Approach 3: Tabulation
// In this approach, we use tabulation (bottom-up) to fill the DP table and find the minimum energy required.

int jumpFrog(int n, int k, vector<int>& heights) {
    vector<int> dp(n + 1, INT_MAX);

    // Base case: Energy required to reach the 1st stair is 0.
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k && i - j >= 1; j++) {
            // Calculate the energy required to reach the ith stair from (i-j)th stair.
            int energy = dp[i - j] + abs(heights[i - 1] - heights[i - j - 1]);

            // Update the minimum energy if the current energy is smaller.
            dp[i] = min(dp[i], energy);
        }
    }

    return dp[n];
}




// Approach 4: Space Optimization
// In this approach, we use space optimization to reduce the space complexity to O(k).

int jumpFrog(int n, int k, vector<int>& heights) {
    vector<int> dp(k + 1, INT_MAX);

    // Base case: Energy required to reach the 1st stair is 0.
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k && i - j >= 1; j++) {
            // Calculate the energy required to reach the ith stair from (i-j)th stair.
            int energy = dp[(i - j) % (k + 1)] + abs(heights[i - 1] - heights[i - j - 1]);

            // Update the minimum energy if the current energy is smaller.
            dp[i % (k + 1)] = min(dp[i % (k + 1)], energy);
        }
    }

    return dp[n % (k + 1)];
}
