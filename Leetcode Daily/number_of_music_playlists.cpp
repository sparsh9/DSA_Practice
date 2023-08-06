#define mod 1000000007

// Approach : Recursion


class Solution {
public:
    // Function to compute the number of playlists with given constraints
    long solve(int n, int goal, int k) {
        // Base case: If there are no songs to choose (n==0) and goal is 0 (playlist is formed), return 1.
        if (n == 0 && goal == 0) return 1;
        // If either n or goal is 0, it's not possible to form the playlist, so return 0.
        if (n == 0 || goal == 0) return 0;

        // Choose a song from the remaining n songs and reduce goal by 1.
        // The number of ways to choose the song is (n * solve(n-1, goal-1, k)) mod mod.
        long take = ((n % mod) * (solve(n-1, goal-1, k) % mod)) % mod;

        // If k > 0, we must ensure that we don't repeat songs within k positions.
        // If we already have k songs in the playlist, we must choose a song that is not within k positions of the last song chosen.
        // The number of ways to do this is (max((n-k),0) * solve(n, goal-1, k)) mod mod.
        long notTake = ((max((n-k), 0) % mod) * (solve(n, goal-1, k) % mod)) % mod;

        // apply modulo operation to avoid integer overflow.
        return (take % mod + notTake % mod) % mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        int ans = solve(n, goal, k) % mod;
        return ans;
    }
};



// Appraoch : Recursion + Memoization

class Solution {
public:
    // Function to compute the number of playlists with given constraints
    long solve(int n, int goal, int k, vector<vector<long>>& dp) {
        // Base case: If there are no songs to choose (n==0) and goal is 0 (playlist is formed), return 1.
        if (n == 0 && goal == 0) return 1;
        // If either n or goal is 0, it's not possible to form the playlist, so return 0.
        if (n == 0 || goal == 0) return 0;

        // If the subproblem is already solved, return the answer.
        if (dp[n][goal] != -1) return dp[n][goal];

        // Choose a song from the remaining n songs and reduce goal by 1.
        // The number of ways to choose the song is (n * solve(n-1, goal-1, k)) mod mod.
        long take = ((n % mod) * (solve(n-1, goal-1, k, dp) % mod)) % mod;

        // If k > 0, we must ensure that we don't repeat songs within k positions.
        // If we already have k songs in the playlist, we must choose a song that is not within k positions of the last song chosen.
        // The number of ways to do this is (max((n-k),0) * solve(n, goal-1, k)) mod mod.
        long notTake = ((max((n-k), 0) % mod) * (solve(n, goal-1, k, dp) % mod)) % mod;

        // apply modulo operation to avoid integer overflow.
        return dp[n][goal] = (take % mod + notTake % mod) % mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        // Create a DP table to store the results of subproblems
        vector<vector<long>> dp(n+1, vector<long>(goal+1, -1));
        // we chose (n+1) and (goal+1) size because we need to store all the values from 0 to n. 
        // where 0 represent no songs and n represent nth song.

        int ans = solve(n, goal, k, dp) % mod;
        return ans;
    }
};
