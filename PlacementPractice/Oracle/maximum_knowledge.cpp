#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxKnowledge(int d, int n, int k, vector<int>& s, vector<int>& e, vector<int>& a) {
    // Create a vector of vectors to store the maximum knowledge on each day
    vector<vector<int>> dp(d + 1, vector<int>(k + 1, 0));

    // Iterate through each meeting and update the DP table
    for (int i = 0; i < n; i++) {
        int start = s[i];
        int end = e[i];
        int knowledge = a[i];

        // Iterate through each day from the start of the meeting to the end
        for (int day = start; day <= end; day++) {
            // Try attending k meetings on each day and update the maximum knowledge
            for (int j = k; j > 0; j--) {
                dp[day][j] = max(dp[day][j], dp[day - 1][j - 1] + knowledge);
            }
        }
    }

    // Find the maximum knowledge gained on any day
    int max_knowledge = 0;
    for (int day = 0; day <= d; day++) {
        max_knowledge = max(max_knowledge, dp[day][k]);
    }

    return max_knowledge;
}

int main() {
    int d = 10;
    int n = 4;
    int k = 2;
    vector<int> s = {2, 5, 4, 3};
    vector<int> e = {8, 9, 7, 5};
    vector<int> a = {800, 1600, 200, 400};

    int result = maxKnowledge(d, n, k, s, e, a);
    cout << "Maximum knowledge gained in a day: " << result << endl;

    return 0;
}
